/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:24:14 by malourei          #+#    #+#             */
/*   Updated: 2025/02/05 19:05:01 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

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
	execve(path, argv, envp);
	if (execve(path, argv, envp) == -1)
	{
		free_env(argv);
		return ;
	}
}

void	child_one(t_pipex *pipex, char **env, char *cmd_path, t_cmd *node)
{
	if (dup2(pipex->fds[0].fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup1");
		return ;
	}
	ft_close_all_1(pipex);
	execve2(cmd_path, node, env);
}

void	child_two(t_pipex *pipex, char **env, char *cmd_path, t_cmd *node)
{
	int	i;
	t_cmd	*tmp;

	tmp = node;
	i = -1;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	if (access(cmd_path, F_OK) != 0)
	{
		write(2, "command not found\n", 18);
		return ;
	}
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
	{
		perror("pid2");
		free(pipex->pids);
		return ;
	}
	if (pipex->pids[i] == 0)
	{
		if (dup2(pipex->fds[i].fd[0], STDIN_FILENO) < 0)
		{
			perror("dup2");
			return ;
		}
		ft_close_all_p(pipex);
		execve2(cmd_path, tmp, env);
	}
}

void	ft_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	ft_close_all_p(pipex);
	while (i < pipex->cmd_argc)
	{
		waitpid(pipex->pids[i], NULL, 0);
		i++;
	}
	clean_all(pipex);
}
