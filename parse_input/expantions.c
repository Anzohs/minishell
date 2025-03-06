/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:22:59 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/06 20:01:04 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	expantions(t_string *s)
{
	int			i;
	int			c;
	t_string	str;

	if (!s || !*s)
		return ;
	str = *s;
	i = -1;
	c = 0;
	while (str[++i] != 0)
	{
		if ((str[i] == '"' || str[i] == '\'') && !c)
			c = str[i];
		else if (str[i] == c)
			c = 0;
		else if (str[i] == '$' && (!c || c == '"') && str[i + 1]
			&& (ft_isalpha(str[i + 1]) || str[i + 1] == '?' \
				|| str[i + 1] == '_'))
			str[i] = 2;
	}
}
