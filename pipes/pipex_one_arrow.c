/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_one_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essmpt <essmpt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:15:07 by essmpt            #+#    #+#             */
/*   Updated: 2025/01/31 22:46:03 by essmpt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	one_arrow(t_node *m)
{
	int		pid;
	int		file;
	char	*cmd;
	char	**strs;

	if (!ft_strcmp(m->entry.key, ">") && !m->entry.args[0])
	{
		write(2, "error near \"newline\" found\n", 27);
		return ;
	}
	if (!ft_strcmp(m->entry.key, ">"))
	{
		file = open(m->entry.args[0], O_CREAT | O_TRUNC, 0644);
		if (file < 0)
		{
			perror("file");
			return ;
		}
		ft_close(file);
		return ;
	}
	cmd = ft_strjoin("/usr/bin/", m->entry.key);
	if (cmd == NULL)
		return;
	if (!m->entry.arrow[1])
	{
		write(2, "error near \"newline\" found2\n", 28);
		free(cmd);
		free_env(m->entry.arrow);
		return ;
	}
	file = open(m->entry.arrow[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
		free_env(m->entry.arrow);
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
	free_env(m->entry.arrow);
	ft_close(file);
	waitpid(pid, NULL, 0);
}
