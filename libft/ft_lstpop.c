/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:31:13 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/09 17:46:27 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **lst, t_list *node)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *lst;
	prev = NULL;
	if (!node)
		return ;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, node->content))
		{
			if (!prev)
				(*lst) = (*lst)->next;
			else
				prev->next = tmp->next;
			ft_lstdelone(tmp, free);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
