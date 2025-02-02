/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:15:28 by hladeiro          #+#    #+#             */
/*   Updated: 2024/04/18 19:15:29 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*list_t;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	if (!new_list)
	{
		new_list = ft_lstnew(f(lst->content));
		if (!new_list->content)
			del(new_list->content);
		lst = lst->next;
	}
	while (lst)
	{
		list_t = ft_lstnew(f(lst->content));
		ft_lstadd_back(&new_list, list_t);
		lst = lst->next;
	}
	return (new_list);
}
