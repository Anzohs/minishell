/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_two_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essmpt <essmpt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:15:07 by essmpt            #+#    #+#             */
/*   Updated: 2025/01/26 00:21:27 by essmpt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	two_arrow()
{
	int		pid;
	int		fd[2];
	int		file;
	char	*cmd;
	char	*strs[] = {mini()->commands->entry.key, NULL};

	if (!mini()->commands->entry.args[0])
	{
		write(2, "error near \"newline\" found3\n", 28);
		return ;
	}
	if (!ft_strcmp(mini()->commands->entry.key, ">>"))
	{
		file = open(mini()->commands->entry.args[0], O_CREAT, 0644);
		if (file < 0)
		{
			perror("file");
			return ;
		}
		ft_close(file);
		return ;
	}
	cmd = ft_strjoin("/usr/bin/", mini()->commands->entry.key);
	if (cmd == NULL)
		return;
	if (access(cmd, F_OK) != 0)
	{
		write(2, "FILE: cmd not found\n", 20);
		free(cmd);
		return ;
	}
	if (!mini()->commands->entry.args[1])
	{
		write(2, "error near \"newline\" found4\n", 28);
		free(cmd);
		return ;
	}
	file = open(mini()->commands->entry.args[1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (file < 0)
	{
		perror("file");
		free(cmd);
		return ;
	}
	printf("MACHO\n");
	if (pipe(fd) < 0)
	{
		write(2, "pipe_open\n", 10);
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		write(2, "pid_file\n", 9);
		return ;
	}
	if (pid == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
		{
			write(2, "file_dup1\n", 10);
			return ;
		}
		if (dup2(file, STDOUT_FILENO) < 0)
		{
			write(2, "file_file\n", 10);
			return ;
		}
		ft_close(fd[0]);
		ft_close(fd[1]);
		ft_close(file);
		execve(cmd, strs, mini()->super_env);
		write(2, "EXECVE_FILE\n", 12);
	}
	free(cmd);
	ft_close(fd[0]);
	ft_close(fd[1]);
	ft_close(file);
	waitpid(pid, NULL, 0);
}
