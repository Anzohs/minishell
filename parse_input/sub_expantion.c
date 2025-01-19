/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_expantion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/19 15:06:24 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_string	sub_expantion(t_string s, t_string str)
{
	t_string	new;
	int			i;
	int			j;

	new = ft_calloc(ft_strlen(s) + ft_strlen(str) + 1, sizeof(char));
	if (!new)
		exit(0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s)[i] == 2)
		{
			i++;
			while (s[i] && ft_isalpha(s[i]))
				i++;
			while (*str != 0)
				new[j++] = *str++;
			while (s[i])
				new[j++] = (s)[i++];
			break ;
		}
		else
			new[j++] = s[i++];
	}
	while (s[i])
		new[j++] = s[i++];
	free(s);
	return (new);
}
