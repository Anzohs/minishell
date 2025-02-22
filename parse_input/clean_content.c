/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:22:48 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/22 17:11:56 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
/*
static void	take_spaces(t_string *s)
{
	int	i;

	i = ft_strlen(*s) - 1;
	if (i == -1)
		return ;
	while (i && (*s)[i] == ' ')
		(*s)[i--] = 0;
}
*/

static void t_quotes(t_string *matrix)
{
	int i;

	i = -1;
	while (matrix[++i])
		take_quotes(&matrix[i]);
}

void clean_content(void)
{
	t_cmd	*lst;

	lst = mini()->cmd;
	while (lst)
	{
		create_matrix(&lst);
		t_quotes(lst->matrix);
		lst = lst->next;
	}
}
