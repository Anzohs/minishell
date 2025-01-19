/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:09:12 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/19 15:12:33 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_string	get_var(t_string s)
{
	int			i;
	int			j;
	t_string	str;
	t_string	c;

	i = -1;
	while (s[++i])
	{
		if (s[i] == 2)
		{
			j = i + 1;
			while (s[j] && ft_isalpha(s[j]))
				j++;
			str = ft_substr(s + i + 1, 0, j - i -1);
			c = ft_lsthas(mini()->env, str);
			free(str);
			if (c[0] == '=')
				return (c + 1);
			return (c);
		}
	}
	return ("");
}
