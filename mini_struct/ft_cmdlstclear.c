/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdlstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:31:43 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/16 21:31:46 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_cmdlstclear(t_cmd **lst, void (*del)(t_cmd **lst))
{
	t_cmd	*list_t;
	t_cmd	*list_temp;

	list_t = *lst;
	if (!*lst || !del)
		return ;
	while (list_t)
	{
		list_temp = list_t->next;
		del(&list_t);
		list_t = list_temp;
	}
	*lst = NULL;
}
