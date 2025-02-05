/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttomatrtix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:27:58 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/05 20:34:26 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lsttomatrix(t_list *lst)
{
	char	**matrix;
	int		l;
	int		i;

	l = ft_lstsize(lst);
	matrix = ft_calloc(l + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix[l] = NULL;
	i = -1;
	while (++i < l && lst)
	{
		matrix[i] = ft_strdup(lst->content);
		lst = lst->next;
	}
	return (matrix);
}
