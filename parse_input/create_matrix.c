/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:03:12 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/22 17:18:34 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "parsing.h"

static void	mark_spaces(t_string *s)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while ((*s)[++i])
	{
		if (((*s)[i] == '"' || (*s)[i] == '\'') && !c)
			c = (*s)[i];
		else if ((*s)[i] == c)
			c = 0;
		else if ((*s)[i] == ' ' && !c)
			(*s)[i] = 2;
	}
}

void	create_matrix(t_cmd **cmd)
{
	expantions(&(*cmd)->arg);
	while (is_expantion((*cmd)->arg))
		(*cmd)->arg = sub_expantion((*cmd)->arg, get_var((*cmd)->arg));
	mark_spaces(&(*cmd)->arg);
	(*cmd)->matrix = ft_split((*cmd)->arg, 2);
	(*cmd)->cmd = ft_strdup((*cmd)->matrix[0]);
}
