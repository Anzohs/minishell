/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:20:42 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/23 21:25:16 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include <stdbool.h>

static int	get_last_fd(t_fd *fd)
{
	t_fd	*f;
	int		file;

	f = fd;
	file = 1;
	while (f)
	{
		if ((f->type == CREATE || f->type == APPEND))
			file = f->fd;
		f = f->next;
	}
	return (file);
}

static int	get_last_read(t_fd *fd)
{
	t_fd	*f;
	int		file;
	bool	here;

	f = fd;
	file = 1;
	here = false;
	while (f)
	{
		if (f->type == REVERSE && !here)
			file = f->fd;
		else if (f->type == HEREDOC)
		{
			file = 0;
			here = true;
		}
		f = f->next;
	}
	return (file);
}

bool	change_fd(t_cmd **cmd)
{
	t_fd	*f;

	f = (*cmd)->fd;
	while (f)
	{
		take_quotes(&f->name);
		if (f->type == CREATE)
			f->fd = open(f->name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (f->type == APPEND)
			f->fd = open(f->name, O_CREAT | O_WRONLY | O_APPEND, 0664);
		if (f->type == REVERSE)
			f->fd = open(f->name, O_RDONLY, 0664);
		if (f->type == HEREDOC)
			f->fd = open(".heredoc", O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (f->fd == -1)
		{
			ft_putstr_fd(f->name, 2);
			ft_putendl_fd(": No such file or directory", 2);
		}
		f = f->next;
	}
	(*cmd)->w = get_last_fd((*cmd)->fd);
	(*cmd)->read = get_last_read((*cmd)->fd);
	return (true);
}
