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
	t_string	s;
	t_string	p;

	s = ft_strjoin((*cmd)->cmd, " ");
	p = ft_strjoin(s, (*cmd)->arg);
	free(s);
	parse_redirection(cmd, &p);
	expantions(&p);
	while (is_expantion(p))
		p = sub_expantion(p, get_var(p));
	mark_spaces(&p);
	(*cmd)->matrix = ft_split(p, 2);
	free(p);
}
