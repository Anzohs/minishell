/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsthas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:19:47 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/23 21:20:40 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lsthas(t_list *lst, const char *str)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, str, ft_strlen(str)))
		{
			if (*(tmp->content + ft_strlen(str)) == '=' || \
							str[ft_strlen(str) - 1] == '=')
				return (ft_strchr(tmp->content, '='));
		}
		tmp = tmp->next;
	}
	return ("");
}
