/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_expantion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:39:37 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/08 19:09:21 by hladeiro         ###   ########.fr       */
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
		return (ft_strdup(""));
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
