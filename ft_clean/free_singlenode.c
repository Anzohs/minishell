/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_singlenode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:34:15 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/04 18:34:28 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_search/ft_search.h"

void	free_singlenode(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	n = n->next;
	free(tmp->entry.key);
	free(tmp->entry.value);
	free(tmp);
}
