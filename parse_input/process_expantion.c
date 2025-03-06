/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_expantion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:51:08 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/06 19:59:57 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	skip_alpha(t_string s, int i)
{
	if (s[i] == '?')
		return (++i);
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

void	process_expansion(t_string s, t_string str, t_string it, t_string n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == 2)
		{
			i++;
			i = skip_alpha(s, i);
			if (s[i - 1] == '?')
				copy_str(n, it, &j);
			else
				copy_str(n, str, &j);
			copy_remaining(n, s, &i, &j);
			break ;
		}
		else
			n[j++] = s[i++];
	}
	copy_remaining(n, s, &i, &j);
}
