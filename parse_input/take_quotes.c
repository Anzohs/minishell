/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:47:11 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/01 18:47:45 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	take_quotes(t_string *str)
{
	t_string	s;
	int			i;
	int			y;
	int			c;

	s = *str;
	i = -1;
	y = -1;
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else
			(*str)[++y] = s[i];
	}
	while (y < i)
		(*str)[++y] = 0;
}
