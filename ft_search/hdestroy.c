/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdestroy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:31:22 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/24 19:02:28 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_search.h"

static void	free_n(t_node *node)
{
	t_node	*temp;

	if (!node)
		return ;
	while (node->next)
	{
		temp = node->next;
		free(node->entry.key);
		free(node->entry.value);
		free(node);
		node = temp;
	}
	free(node->entry.key);
	free(node->entry.value);
	free(node);
}

void	hdestroy(t_hash *ht)
{
	size_t	len;

	if (!ht)
		return ;
	len = -1;
	while (++len < ht->len)
		free_n(ht->node[len]);
	free(ht->node);
	free(ht);
}
