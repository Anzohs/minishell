/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:16:43 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/24 01:16:45 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static t_string	*new_matrix(t_string *matrix)
{
	int			i;
	t_string	*s;
	int			j;

	i = matrix_len(matrix);
	if (!i)
		return (free_env(matrix), NULL);
	s = ft_calloc(i, sizeof(t_string));
	if (!s)
		return (free_env(matrix), NULL);
	j = 0;
	while (++j < i)
		s[j - 1] = ft_strdup(matrix[j]);
	return (free_env(matrix), s);
}

static void	new_cmd(t_cmd **cmd)
{
	t_cmd	*lst;

	lst = *cmd;
	free(lst->cmd);
	lst->cmd = ft_strdup(lst->matrix[0]);
	lst->matrix = new_matrix(lst->matrix);
}

void	change_cmd(t_cmd **cmd)
{
	t_cmd	*lst;

	lst = *cmd;
	while (lst)
	{
		new_cmd(&lst);
		lst = lst->next;
	}
}
