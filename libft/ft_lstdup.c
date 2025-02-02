/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:59:14 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/15 23:59:15 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdup(t_list **list, t_list **head)
{
	t_list	*lst;
	t_list	*tmp;
	char	*content;

	tmp = *list;
	while (tmp)
	{
		content = ft_strdup(tmp->content);
		if (!content)
		{
			ft_lstclear(head, free);
			return ;
		}
		lst = ft_lstnew(content);
		if (!lst)
		{
			free(content);
			ft_lstclear(head, free);
			exit(0);
		}
		ft_lstadd_back(head, lst);
		tmp = tmp->next;
	}
}
