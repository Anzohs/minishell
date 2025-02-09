/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:45:09 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/09 18:10:18 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_cmd	*ft_cmdlst_new(char *cmd, char *arg)
{
	t_cmd	*list;

	list = (t_cmd *)ft_calloc(1, sizeof(*list));
	if (!list)
		return (NULL);
	list->cmd = ft_strdup(cmd);
	if (!list->cmd)
	{
		free(list);
		exit(0);
	}
	list->arg = ft_strdup(arg);
	if (!list->arg)
	{
		ft_cmdlstdelone(&list);
		exit(0);
	}
	list->w = STDOUT_FILENO;
	list->read = STDIN_FILENO;
	list->matrix = NULL;
	list->fd = NULL;
	list->next = NULL;
	return (list);
}
