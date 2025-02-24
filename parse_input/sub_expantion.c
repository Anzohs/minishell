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

static int	skip_alpha(t_string s, int i)
{
	while (s[i] && ft_isalpha(s[i]))
		i++;
	return (i);
}

static void	copy_str(t_string n, t_string str, int *j)
{
	while (*str != 0)
		n[(*j)++] = *str++;
}

static void	copy_remaining(t_string new, t_string s, int *i, int *j)
{
	while (s[*i])
		new[(*j)++] = s[(*i)++];
}

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
			i = skip_alpha(s, i);
			copy_str(new, str, &j);
			copy_remaining(new, s, &i, &j);
			break ;
		}
		else
			new[j++] = s[i++];
	}
	copy_remaining(new, s, &i, &j);
	return (free(s), new);
}
