/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:24:53 by essmpt            #+#    #+#             */
/*   Updated: 2025/02/10 15:03:19 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../mini_struct/mini.h"
#include <unistd.h>

static void	start_pipe_1(t_pipex *pipex, t_cmd *argv2)
{
	int	i;

	i = 0;
	if (pipe(pipex->fds[0].fd) < 0)
	{
		perror("pipe");
		return ;
	}
	if (access(pipex->paths[0], F_OK) != 0)
	{
		write(2, "command not found\n", 18);
		return ;
	}
	pipex->pids[i] = fork();
	if (pipex->pids[i] == 0)
	{
		if (pipex->is_doc == 0)
			child_one(pipex, pipex->env, pipex->paths[0], argv2);
	}
	if (pipex->pids[i] < 0)
	{
		perror("pid");
		free(pipex->pids);
		return ;
	}
}

static void	start_multi2_pip(t_pipex *pipex, int i, char *cmd_path, t_cmd *node)
{
	if (access(cmd_path, F_OK) != 0)
	{
		printf("command not found\n");
		return ;
	}
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
	{
		perror("pid");
		free(pipex->pids);
		return ;
	}
	if (pipex->pids[i] == 0)
	{
		if (pipex->pids[i - 1])
		{
			if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
			{
				perror("dup5");
				return ;
			}
		}
		if (dup2(pipex->fds[i].fd[1], STDOUT_FILENO) < 0)
		{
			perror("dup6");
			return ;
		}
		ft_close_all_m(pipex, i);
		dup2(node->w, STDOUT_FILENO);
		dup2(node->read, STDIN_FILENO);
		execve2(cmd_path, node, pipex->env);
	}
}

static void	one_cmd(t_pipex *pipex, t_mini *mini)
{
	int	flag;

	flag = 0;
	if (access(pipex->path2, F_OK) != 0)
	{
		pipex->cmd_argc -= 1;
		printf("command not found: %s\n", mini->cmd->cmd);
		return ;
	}
	if (pipe(pipex->fds[0].fd) < 0)
	{
		perror("pipe");
		return ;
	}
	if (mini->cmd->w == 1)
		flag = 1;
	pipex->pids[0] = fork();
	if (pipex->pids[0] < 0)
	{
		perror("pid");
		free(pipex->pids);
		return ;
	}

	if (pipex->pids[0] == 0)
	{
		if (flag)
		{
			dup2(mini->cmd->read , STDIN_FILENO);
			ft_close(mini->cmd->read);
		}
		else
		{
			dup2(mini->cmd->w, STDOUT_FILENO);
			ft_close(mini->cmd->w);
		}
		ft_close(pipex->fds[0].fd[0]);
		ft_close(pipex->fds[0].fd[1]);
		ft_close(mini->cmd->read);
		ft_close(mini->cmd->w);
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
	{
		one_cmd(pipex, mini);
		return ;
	}
	start_pipe_1(pipex, n);
	node = n;
	i = 0;
	j = argc - 1;
	while (++i < j && n)
	{
		node = node->next;
		if (pipe(pipex->fds[i].fd) < 0)
		{
			perror("pipe2");
			return ;
		}
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

void has_heredoc(t_cmd *cmd)
{
	t_cmd	*temp;
	t_fd	*f;

	temp = cmd;
	while (temp)
	{
		f = temp->fd;
		while (f)
		{
			if (f->type == HEREDOC)
				start_here_doc(temp, ft_lsttomatrix(mini()->env));
			f = f->next;
		}
		temp = temp->next;
	}
}


void	pipex(void)
{
	t_pipex	pipex;

	pipex = (t_pipex){0};
	validate_args(mini()->cmd, &pipex.cmd_argc);
	count_pids(&pipex, pipex.cmd_argc);
	pipex.env = ft_lsttomatrix(mini()->env);
	get_strs_envs(&pipex);
	if (!find_full_cmd(&pipex, mini()->cmd))
	{
		clean_all(&pipex);
		return ;
	}

	start_multi_pipe(&pipex, mini(), ft_cmdsize(mini()->cmd), mini()->cmd);
	ft_parent(&pipex);
	return ;
}
