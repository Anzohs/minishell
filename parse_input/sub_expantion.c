/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_expantion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:39:37 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/06 19:30:57 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../mini_struct/mini.h"

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

static void	t_string_new(t_string *new, t_string s, t_string str, t_string it)
{
	if (!str || *str == 0)
		*new = ft_calloc(ft_strlen(s) + ft_strlen(it) + 1, sizeof(char));
	else
		*new = ft_calloc(ft_strlen(s) + ft_strlen(str) + 1, sizeof(char));
}

t_string	sub_expantion(t_string s, t_string str)
{
	t_string	new;
	t_string	it;
	int			i;
	int			j;

	it = ft_itoa(mini()->exit_code);
	t_string_new(&new, s, str, it);
	if (!new)
		return (free(it), ft_strdup(""));
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s)[i] == 2)
		{
			i++;
			i = skip_alpha(s, i);
			if (s[i - 1] == '?')
				copy_str(new, it, &j);
			else
				copy_str(new, str, &j);
			copy_remaining(new, s, &i, &j);
			break ;
		}
		else
			new[j++] = s[i++];
	}
	copy_remaining(new, s, &i, &j);
	return (free(s), free(it), new);
}
