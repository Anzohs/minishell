/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:10:32 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/04 21:02:34 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetlst(t_list **lst, const char *str)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, str, ft_strlen(str)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
