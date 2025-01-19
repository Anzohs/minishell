/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essmpt <essmpt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:52:43 by malourei          #+#    #+#             */
/*   Updated: 2025/01/19 23:02:40 by essmpt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "pipex.h"

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

static void	here_doc(char *limiter, int fd[2])
{
	char	*line;

	ft_close(fd[0]);
	while (1)
	{
		write(1, "> ", 2);
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
	ft_close(fd[1]);
}

int	start_here_doc(t_pipex *pipex, t_node *n)
{
	int pidefd[2];
	int	pid;

	if (pipe(pidefd) < 0)
	{
		perror("pipe1");
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("pid3");
		return ;
	}
	if (pid == 0)
		here_doc(n->entry.value, pidefd);
	else
	{
		ft_close(pidefd[1]);
		waitpid(pid, NULL , 0);
		return (pidefd[0]);
	}
}
