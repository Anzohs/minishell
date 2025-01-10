/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:52:43 by malourei          #+#    #+#             */
/*   Updated: 2025/01/10 17:09:24 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "pipex.h"
#include <fcntl.h>

void	ft_child_doc_one(t_pipex *pipex, char **env, char *cmd_path, t_node *n)
{
	if (dup2(pipex->fds[0].fd[0], STDIN_FILENO) < 0)
	{
		perror("dup1");
		exit(1);
	}
	if (dup2(pipex->fds[1].fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(1);
	}
	ft_close(pipex->fds[0].fd[0]);
	ft_close(pipex->fds[0].fd[1]);
	ft_close(pipex->fds[1].fd[0]);
	ft_close(pipex->fds[1].fd[1]);
	execve2(cmd_path, n, env, pipex);
	exit(0);
}

static void	here_doc(char *limiter, int fd[2], t_pipex *pipex)
{
	char	*line;

	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	ft_close(fd[0]);
	ft_close(fd[1]);
	clean_all(pipex);
}

void	start_here_doc(t_pipex *pipex, t_node *n)
{
	pipex->i_multi_argv = 2;
	pipex->is_doc = 1;
	if (pipe(pipex->fds[0].fd) < 0)
	{
		perror("pipe1");
		return ;
	}
	pipex->pids[0] = fork();
	if (pipex->pids[0] < 0)
	{
		perror("pid3");
		return ;
	}
	if (pipex->pids[0] == 0)
		here_doc(n->entry.value, pipex->fds[0].fd, pipex);
	ft_close(pipex->fds[0].fd[1]);
}
