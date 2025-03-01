/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:24:14 by malourei          #+#    #+#             */
/*   Updated: 2025/03/01 00:21:56 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"
#include <unistd.h>

t_string	*fusion_strs(t_cmd *cmd)
{
	t_string	*matrix;
	int			i;

	matrix = ft_calloc(matrix_len(cmd->matrix) + 2, sizeof(t_string));
	matrix[0] = ft_strdup(cmd->cmd);
	i = 0;
	while (cmd->matrix[i])
	{
		matrix[i + 1] = ft_strdup(cmd->matrix[i]);
		i++;
	}
	matrix[i + 1] = NULL;
	return (matrix);
}

void	execve2(const char *path, t_cmd *node, char *const envp[])
{
	char	**argv;

	argv = fusion_strs(node);
	if (execve(path, argv, envp) == -1)
		return (free_env(argv), (void)argv);
}

void	child_one(t_pipex *pipex, char **env, char *cmd_path, t_cmd *node)
{
	node->read = read_file_get_file(node->fd);
	node->w = write_file_get_file(node->fd);
	if (node->read >= 3)
	{
		if (dup2(node->read, STDIN_FILENO) < 0)
			return (perror("dup1"), (void)pipex);
	}
	if (node->w >= 3)
	{
		if (dup2(node->w, STDOUT_FILENO) < 0)
			return (perror("dup3"), (void)pipex);
	}
	if (node->w < 3)
	{
		if (dup2(pipex->fds[0].fd[1], STDOUT_FILENO) < 0)
			return (perror("dup4"), (void)pipex);
	}
	if (is_builtin(node->cmd))
		return (clean_all(pipex), execute_builtin(node, STDOUT_FILENO, 1),
			(void)1);
	ft_close_all_1(pipex);
	ft_close_all_files(node);
	execve2(cmd_path, node, env);
}

void	child_two(t_pipex *pipex, char **env, char *cmd_path, t_cmd *node)
{
	int		i;
	t_cmd	*tmp;

	tmp = node;
	i = 0;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	if (!is_builtin(tmp->cmd) && access(cmd_path, F_OK) != 0)
		return (ft_putendl_fd("command not found", STDERR_FILENO),
			(void)cmd_path);
	if (!good_files(tmp) || !*tmp->cmd)
		return ;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (perror("pid2"), free(pipex->pids), (void)cmd_path);
	if (pipex->pids[i] == 0)
	{
		tmp->read = read_file_get_file(tmp->fd);
		tmp->w = write_file_get_file(tmp->fd);
		if (tmp->read >= 3)
		{
			if (dup2(tmp->read, STDIN_FILENO) < 0)
				return (perror("dup5"), (void)cmd_path);
		}
		if (tmp->w >= 3)
		{
			if (dup2(tmp->w, STDOUT_FILENO) < 0)
				return (perror("dup6"), (void)cmd_path);
		}
		if (tmp->read < 3)
		{
			if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
				return (perror("dup69"), (void)cmd_path);
		}
		if (is_builtin(tmp->cmd))
			return (clean_all(pipex), execute_builtin(tmp, STDOUT_FILENO, 1),
				(void)i);
		ft_close_all_p(pipex);
		ft_close_all_files(node);
		execve2(cmd_path, tmp, env);
	}
}

void	ft_parent(t_pipex *pipex)
{
	int	i;

	i = -1;
	ft_close_all_p(pipex);
	while (++i < pipex->cmd_argc)
		waitpid(pipex->pids[i], NULL, 0);
	clean_all(pipex);
}
