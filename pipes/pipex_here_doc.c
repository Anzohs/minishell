/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:52:43 by malourei          #+#    #+#             */
/*   Updated: 2025/02/17 21:29:59 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"

static void	here_doc(char *limiter, int fd[2])
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	return (ft_close(fd[1])) ;
}

static void	parent(int fd[2], int pid, t_cmd *m)
{
	(void)m;
	ft_close(fd[0]);
	ft_close(fd[1]);
	waitpid(pid, NULL, 0);
	return ;
}

void	clear_pipe(int fd[2])
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

	if (!*mini()->cmd->cmd)
		return ;
	strs = fusion_strs(mini()->cmd);
	*pid = fork();
	if (*pid < 0)
		return (perror("pid3"));
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

/* 	else if (ft_strcmp(m->cmd, "<<") && !m->arrow[1])
	{
		write(2, "error near \"newline\" found5\n", 28);
		free_matrix(m->arrow);
		return ;
	} */
	if (pipe(pipefd) < 0)
	{
		perror("pipe1");
		return ;
	}
	ft_here_one(pipefd, &pid, m->fd->name, env);
	parent(pipefd, pid, m);
	return ;
}
