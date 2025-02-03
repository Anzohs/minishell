/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:17:20 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/03 21:18:53 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp_(char *c, char *d)
{
	int	i;

	i = 0;
	if (!c && !d)
		return (0);
	if (!c || !d)
		return (1);
	while (c[i] == d[i] && d[i] && c[i])
		i++;
	return (c[i] - d[i]);
}


static void	ft_lstswap(t_list *a, t_list *b)
{
	char *temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}


void	ft_lstsort(t_list **head)
{
	t_list	*current;
	t_list	*next;
	int		swapped;

	if (!head || !*head)
		return;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *head;
		while (current->next != NULL)
		{
			next = current->next;
			if (ft_strcmp_(current->content, next->content) > 0)
			{
				ft_lstswap(current, next);
				swapped = 1;
			}
			current = current->next;
		}
	}
}
