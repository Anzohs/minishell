/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_one_arrow_reverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: essmpt <essmpt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:03:50 by essmpt            #+#    #+#             */
/*   Updated: 2025/02/01 00:31:55 by essmpt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	one_arrow_reverse(t_node *m)
{
	int		pid;
	int		file;
	char	*cmd;
	char	**strs;

	if (!ft_strcmp(m->entry.key, "<") && !m->entry.args[0])
	{
		write(2, "error near \"newline\" found5\n", 28);
		return ;
	}
	if (!ft_strcmp(m->entry.key, "<"))
	{
		file = open(m->entry.args[0], O_RDONLY);
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
		write(2, "error near \"newline\" found6\n", 28);
		free(cmd);
		free_env(m->entry.arrow);
		return ;
	}
	file = open(m->entry.arrow[1], O_RDONLY);
	if (file < 0)
	{
		perror("file");
		free(cmd);
		free_env(m->entry.arrow);
		return ;
	}
	if (access(cmd, F_OK) != 0)
	{
		write(2, "ARROW <: cmd not found\n", 23);
		free_env(m->entry.arrow);
		free(cmd);
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
		if (dup2(file, STDIN_FILENO) < 0)
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
