/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:52:43 by malourei          #+#    #+#             */
/*   Updated: 2025/02/20 21:26:30 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"

static void	here_doc_2(char *limiter, int fd[2])
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

static void	parent_2(int fd[2], int pid)
{
	ft_close(fd[0]);
	ft_close(fd[1]);
	waitpid(pid, NULL, 0);
	return ;
}

/* void	clear_pipe_2(int fd[2])
{
	char	buffer[1024];

	while (read(fd[0], buffer, sizeof(buffer)) > 0)
		;
} */

/* static void	start_cmd_2(char **args, char **env, int fd[2])
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
} */

/* void	ft_here_one_2(int fd[2], int *pid, char *n, char **env)
{
	char	**strs;

	strs = fusion_strs(mini()->cmd);
	*pid = fork();
	if (*pid < 0)
		return (perror("pid3"));
	if (*pid == 0)
	{
		here_doc_2(n, fd);
		start_cmd_2(strs, env, fd);
	}
	free_env(strs);
} */

void	start_here_doc_2(t_cmd *m, char **env, t_pipex *pipex)
{
	(void)env;
	if (!ft_strcmp(m->cmd, "<<") && !m->fd->name)
	{
		write(2, "error near \"newline\" found5\n", 28);
		return ;
	}
	if (pipe(pipex->here_fd) < 0)
	{
		perror("pipe1");
		return ;
	}
	pipex->pid_here = fork();
	if (pipex->pid_here < 0)
		return (perror("pid3"));
	if (pipex->pid_here == 0)
	{
		here_doc_2(m->fd->name, pipex->here_fd);
		dup2(pipex->here_fd[0], STDIN_FILENO);
		ft_close(pipex->here_fd[0]);
		ft_close(pipex->here_fd[1]);
	}
/* 	if (!ft_strcmp(m->cmd, "<<"))
		ft_here_one_2(pipefd, &pid, m->matrix[0], env);
	else
		ft_here_one_2(pipefd, &pid, m->fd->name, env); */
	parent_2(pipex->here_fd, pipex->pid_here);
	return ;
}
