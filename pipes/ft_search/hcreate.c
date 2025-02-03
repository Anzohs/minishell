/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hcreate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:31:22 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/24 19:02:31 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_search.h"

t_hash	*hcreate(size_t nel)
{
	t_hash	*hash;
	size_t	l;

	hash = ft_calloc(sizeof(t_hash), nel);
	if (!hash)
		return (NULL);
	hash->node = (t_node **)ft_calloc(sizeof(t_node *), nel);
	if (!hash->node)
	{
		free(hash);
		return (NULL);
	}
	l = 0;
	while (l < nel)
		hash->node[l++] = NULL;
	hash->len = nel;
	return (hash);
}
