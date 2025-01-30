/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_one_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:15:07 by essmpt            #+#    #+#             */
/*   Updated: 2025/01/30 21:28:06 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	one_arrow()
{
	int		pid;
	int		file;
	char	*cmd;
	char	**strs;

	if (!ft_strcmp(mini()->commands->entry.key, ">") && !mini()->commands->entry.args[0])
	{
		write(2, "error near \"newline\" found\n", 27);
		return ;
	}
	if (!ft_strcmp(mini()->commands->entry.key, ">"))
	{
		file = open(mini()->commands->entry.args[0], O_CREAT | O_TRUNC, 0644);
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
	if (!mini()->commands->entry.arrow[1])
	{
		write(2, "error near \"newline\" found2\n", 28);
		free(cmd);
		return ;
	}
	file = open(mini()->commands->entry.arrow[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
	{
		perror("file");
		free(cmd);
		return ;
	}
	if (access(cmd, F_OK) != 0)
	{
		write(2, "ARROW >: cmd not found\n", 23);
		free(cmd);
		ft_close(file);
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
		if (dup2(file, STDOUT_FILENO) < 0)
		{
			write(2, "file_file\n", 10);
			return ;
		}
		ft_close(file);
		strs = fusion_strs();
		execve(cmd, strs, mini()->super_env);
		write(2, "EXECVE_FILE\n", 12);
	}
	free(cmd);
	ft_close(file);
	waitpid(pid, NULL, 0);
}
