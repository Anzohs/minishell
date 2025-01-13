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

#include "../minishell.h"

void	free_node(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	while (tmp)
	{
		tmp = n->next;
		if (n->entry.key)
			free(n->entry.key);
		if (n->entry.value)
			free(n->entry.value);
		if (n->entry.args)
			free_env(n->entry.args);
		free(n);
		n = tmp;
	}
}
