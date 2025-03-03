/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:26:07 by malourei          #+#    #+#             */
/*   Updated: 2025/03/03 16:26:07 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include <time.h>

static int	write_file_get_file(t_fd *f)
{
	t_fd		*f_d;
	t_string	s;
	t_type		x;

	f_d = f;
	s = NULL;
	while (f_d)
	{
		if (f_d->type == APPEND || f_d->type == CREATE)
		{
			s = f_d->name;
			x = f_d->type;
		}
		f_d = f_d->next;
	}
	if (!s)
		return (0);
	if (x == APPEND)
		return (open(s, O_CREAT | O_WRONLY | O_APPEND, 0644));
	return (open(s, O_CREAT | O_TRUNC | O_WRONLY, 0644));
}

static int	read_file_get_file(t_fd *f)
{
	t_fd		*f_d;
	t_string	s;

	f_d = f;
	s = NULL;
	while (f_d)
	{
		if (f_d->type == HEREDOC || f_d->type == REVERSE)
			s = f_d->name;
		f_d = f_d->next;
	}
	if (!s)
		return (0);
	return (open(s, O_RDONLY, 0644));
}

bool	good_files(t_cmd *cmd)
{
	t_fd	*f;

	f = cmd->fd;
	while (f)
	{
		if (f->fd == -1)
			return (false);
		f = f->next;
	}
	return (true);
}

void	check_ridirects(t_cmd *tmp, char *cmd_path)
{
	tmp->read = read_file_get_file(tmp->fd);
	tmp->w = write_file_get_file(tmp->fd);
	if (tmp->read >= 3)
	{
		if (dup2(tmp->read, STDIN_FILENO) < 0)
			return (perror("dup5"), (void)cmd_path);
	}
	if (tmp->w >= 3)
	{
		if (dup2(tmp->w, STDOUT_FILENO) < 0)
			return (perror("dup6"), (void)cmd_path);
	}
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
