/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:35:08 by hladeiro          #+#    #+#             */
/*   Updated: 2024/12/14 16:31:12 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_search/ft_search.h"

void	free_node(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	while (tmp)
	{
		tmp = n->next;
		free(n->entry.key);
		free(n->entry.value);
		free(n);
		n = tmp;
	}
}
