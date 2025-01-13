/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:36:23 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/26 20:39:34 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_search.h"
#include "../ft_clean/ft_clean.h"

void	free_node(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (tmp)
	{
		tmp = tmp->next;
		free(node->entry.key);
		free(node->entry.value);
		free_env(node->entry.args);
		free(node);
		node = tmp;
	}
}
