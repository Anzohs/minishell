/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_expantion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:39:37 by malourei          #+#    #+#             */
/*   Updated: 2025/03/06 20:00:16 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "parsing.h"

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

	it = ft_itoa(mini()->exit_code);
	t_string_new(&new, s, str, it);
	if (!new)
		return (free(it), ft_strdup(""));
	process_expansion(s, str, it, new);
	return (free(s), free(it), new);
}
