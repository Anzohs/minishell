/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:43:59 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/26 20:44:06 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_search.h"

size_t	node_len(t_node *n)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	tmp = n;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
