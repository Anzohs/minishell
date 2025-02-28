/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:14:26 by malourei          #+#    #+#             */
/*   Updated: 2025/02/27 23:27:03 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "pipex.h"

static bool good_files(t_cmd *cmd)
{
	t_fd	*f;

	f = cmd->fd;

	while (f)
	{
		if (f->fd == -1)
			return (false);
		f = f->next;
	}
	return (true);
}

static void start_pipe_1(t_pipex *pipex, t_cmd *cmd)
{
	int i;

	i = 0;
	if (pipe(pipex->fds[0].fd) < 0)
		return (perror("pipe"), (void)i);
	if (!is_builtin(cmd->cmd) && access(pipex->paths[0], F_OK) != 0)
		return (ft_putendl_fd("command not found", STDERR_FILENO), (void)i);
	if (!good_files(cmd))
		return (ft_close_all_1(pipex));
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (perror("pid"), free(pipex->pids), (void)i);
	if (pipex->pids[i] == 0)
	{
		child_one(pipex, pipex->env, pipex->paths[0], cmd);
	}
}


static void start_multi2_pip(t_pipex *pipex, int i, char *cmd_path, t_cmd *node)
{
	if (access(cmd_path, F_OK) != 0)
		return (ft_putendl_fd("command not found", STDERR_FILENO), (void)i);
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (perror("pid"), free(pipex->pids), (void)i);
	if (pipex->pids[i] == 0)
	{
   		node->read = read_file_get_file(node->fd);
		node->w = write_file_get_file(node->fd);
			if (node->w >= 3)
			{
				if (dup2(node->w, STDOUT_FILENO) < 0)
					return (perror("dup7"), (void)i);
			}
			if (node->read >= 3)
			{
				if (dup2(node->read, STDIN_FILENO) < 0)
					return (perror("dup8"), (void)i);
			}
		if (node->read < 3)
		{
			if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
		   		return (perror("dup10"), (void)i);
		}
		if (node->w < 3)
		{
			if (dup2(pipex->fds[i].fd[1], STDOUT_FILENO) < 0)
				return (perror("dup11"), (void)i);
		}
		if (is_builtin(node->cmd))
			return (clean_all(pipex), execute_builtin(node, STDOUT_FILENO, 1), (void)i);
		ft_close_all_m(pipex, i);
		ft_close_all_files(mini()->cmd);
		execve2(cmd_path, node, pipex->env);
	}
}

int read_file_get_file(t_fd *f)
{
	t_fd	*f_d;
	t_string	s;

	f_d = f;
	s = NULL;
	while (f_d)
	{
		if (f_d->type == HEREDOC || f_d->type == REVERSE)
			s = f_d->name;
		f_d = f_d->next;
	}
	if (!s)
		return (0);
	return (open(s, O_RDONLY, 0644));
}

int write_file_get_file(t_fd *f)
{
	t_fd	*f_d;
	t_string	s;
	t_type 		x;

	f_d = f;
	s = NULL;
	while (f_d)
	{
		if (f_d->type == APPEND || f_d->type == CREATE)
		{
			s = f_d->name;
			x = f_d->type;
		}
		f_d = f_d->next;
	}
	if (!s)
		return (0);
	if (x == APPEND)
		return (open(s, O_CREAT | O_WRONLY | O_APPEND, 0644));
	return (open(s, O_CREAT | O_TRUNC | O_WRONLY, 0644));
}


static void	one_cmd(t_pipex *pipex, t_mini *mini)
{
	if (ft_strcmp("", pipex->path2) == 0)
		return (pipex->cmd_argc -= 1, printf("%s : Command not found\n", mini->cmd->cmd), (void)pipex);
	if (pipe(pipex->fds[0].fd) < 0)
		return (perror("pipe"), (void)pipex);
	if (!*mini->cmd->cmd)
		return (ft_close_all_1(pipex));
	if (!good_files(mini->cmd))
		return (ft_close_all_1(pipex));
	pipex->pids[0] = fork();
	if (pipex->pids[0] < 0)
		return (perror("pid"), free(pipex->pids), (void)pipex);
	if (pipex->pids[0] == 0)
	{
		mini->cmd->read = read_file_get_file(mini->cmd->fd);
		mini->cmd->w = write_file_get_file(mini->cmd->fd);
		if (mini->cmd->read >= 3)
		{
			if (dup2(mini->cmd->read, STDIN_FILENO) < 0)
				return (perror("dup3"), (void)pipex);
		}
		if (mini->cmd->w >= 3 )
		{
			if (dup2(mini->cmd->w, STDOUT_FILENO) < 0)
				return (perror("dup3"), (void)pipex);
		}
		ft_close(mini->cmd->read);
		ft_close(mini->cmd->w);
		if (is_builtin(mini->cmd->cmd))
			return (clean_all(pipex), execute_builtin(mini->cmd, STDOUT_FILENO, 1), (void)pipex);
		execve2(pipex->path2, mini->cmd, pipex->env);
	}
	return ;
}

static void	start_multi_pipe(t_pipex *pipex, t_mini *mini, int argc, t_cmd *n)
{
	int		i;
	int		j;
	t_cmd	*node;

	if (argc == 1)
		return (one_cmd(pipex, mini), (void)argc);
	start_pipe_1(pipex, n);
	node = n;
	i = 0;
	j = argc - 1;
	while (++i < j && n)
	{
		node = node->next;
		if (pipe(pipex->fds[i].fd) < 0)
			return (perror("pipe2"), (void)i);
		start_multi2_pip(pipex, i, pipex->paths[i], node);
	}
	child_two(pipex, pipex->env, pipex->path2, n);
}

void	get_strs_envs(t_pipex *pipex)
{
	char	*str;

	str = ft_lsthas(mini()->env, "PATH=");
	if (!*str)
		return ;
	str++;
	pipex->env_path = ft_split(str, ':');
	if (!pipex->env_path)
		return ;
}

void	pipex(void)
{
	t_pipex	pipex;

	pipex = (t_pipex){0};
	check_per_cmd(mini()->cmd);
	validate_args(mini()->cmd, &pipex.cmd_argc);
	count_pids(&pipex, pipex.cmd_argc);
	pipex.env = ft_lsttomatrix(mini()->env);
	get_strs_envs(&pipex);
	if (!find_full_cmd(&pipex, mini()->cmd))
		return (clean_all(&pipex), (void)pipex);
	start_multi_pipe(&pipex, mini(), ft_cmdsize(mini()->cmd), mini()->cmd);
	ft_parent(&pipex);
	return ;
}
