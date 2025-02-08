/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:13:04 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/08 19:26:05 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_fddelone(t_fd **lst)
{
	t_fd	*temp;

	temp = *lst;
	if (temp->name)
		free(temp->name);
	if (temp->fd > 0)
		close(temp->fd);
	free(temp);
}

void	ft_fd_del(t_fd	**fd)
{
	t_fd	*list_t;
	t_fd	*list_temp;

	list_t = *fd;
	if (!*fd)
		return ;
	while (list_t)
	{
		list_temp = list_t->next;
		ft_fddelone(&list_t);
		list_t = list_temp;
	}
	*fd = NULL;
}
