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

static t_string	*new_matrix(t_string *s)
{
	t_string *str;
	int	i = matrix_len(s);
	if (i == 0 || i == 1)
	{
		str = ft_calloc(sizeof(t_string), 1);
		if (!str)
			return (free_env(s), NULL);
		str[0] = NULL;
		return(free_env(s), str);
	}
	str = ft_calloc(sizeof(t_string), i);
	if (!str)
		return (free_env(s), NULL);
	i = 0;
	while (s[i + 1])
	{
		str[i] = s[i + 1];
		i++;
	}
	str[i] = NULL;
	return(free_env(s), str);
}

void	create_matrix(t_cmd **cmd)
{
	int	i;

	i = -1;
	expantions(&(*cmd)->arg);
	while (is_expantion((*cmd)->arg))
		(*cmd)->arg = sub_expantion((*cmd)->arg, get_var((*cmd)->arg));
	mark_spaces(&(*cmd)->arg);
	(*cmd)->matrix = ft_split((*cmd)->arg, 2);
	if (!(*cmd)->matrix)
		return;
	while ((*cmd)->matrix[++i])
		take_quotes(&(*cmd)->matrix[i]);
}
