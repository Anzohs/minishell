/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essmpt <essmpt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:52:43 by malourei          #+#    #+#             */
/*   Updated: 2025/02/08 22:43:37 by essmpt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"

static void	here_doc(char *limiter, int fd[2])
{
	char	*line;

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
	return ;
}

static void	parent(int fd[2], int pid, t_cmd *m)
{
	free_matrix(m->arrow);
	ft_close(fd[0]);
	ft_close(fd[1]);
	waitpid(pid, NULL, 0);
	return ;
}

static void	clear_pipe(int fd[2])
{
	char	buffer[1024];

	while (read(fd[0], buffer, sizeof(buffer)) > 0)
		;
}

static void	start_cmd(char **args, char **env, int fd[2])
{
	char	*cmd;

	cmd = ft_strjoin("/usr/bin/", mini()->cmd->cmd);
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		write(2, "Deu merda\n", 10);
		return ;
	}
	if (access(cmd, F_OK) != 0)
	{
		write(2, "command not found\n", 18);
		clear_pipe(fd);
		free(cmd);
		ft_close(fd[0]);
		ft_close(fd[1]);
		return ;
	}
	ft_close(fd[0]);
	ft_close(fd[1]);
	execve(cmd, args, env);
}

void	ft_here_one(int fd[2], int *pid, char *n, char **env)
{
	char	**strs;

	strs = fusion_strs(mini()->cmd);
	*pid = fork();
	if (*pid < 0)
	{
		perror("pid3");
		return ;
	}
	if (*pid == 0)
	{
		here_doc(n, fd);
		start_cmd(strs, env, fd);
	}
	free_env(strs);
}

void	start_here_doc(t_cmd *m, char **env)
{
	int	pipefd[2];
	int	pid;

	if (!ft_strcmp(m->cmd, "<<") && !m->matrix[0])
	{
		write(2, "error near \"newline\" found5\n", 28);
		return ;
	}
	else if (ft_strcmp(m->cmd, "<<") && !m->arrow[1])
	{
		write(2, "error near \"newline\" found5\n", 28);
		free_matrix(m->arrow);
		return ;
	}
	if (pipe(pipefd) < 0)
	{
		perror("pipe1");
		return ;
	}
	if (!ft_strcmp(m->cmd, "<<"))
		ft_here_one(pipefd, &pid, m->matrix[0], env);
	else
		ft_here_one(pipefd, &pid, m->arrow[1], env);
	parent(pipefd, pid, m);
	return ;
}
