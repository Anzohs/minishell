/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_need.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:42:59 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/01 18:46:23 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	split_need(t_string s)
{
	int	i;
	int	c;

	i = -1;
	if (!s || !*s || *s != 2)
		return (false);
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if (s[i] == 2 && !c)
		{
			while (ft_isalpha(s[++i]))
				;
			if (s[i] != 0 && s[i] != ' ')
				return (false);
			return (true);
		}
	}
	return (false);
}
