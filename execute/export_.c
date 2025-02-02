/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:18:27 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/02 21:30:38 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

/*
static void	ft_lstswap(t_list *a, t_list *b)
{
	char *temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}
*/
/*
static void	ft_lstsort(t_list **head)
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
			if (ft_strcmp(current->content, next->content) > 0)
			{
				ft_lstswap(current, next);
				swapped = 1;
			}
			current = current->next;
		}
	}
}
*/
static void	print_exp(void)
{
	t_list	*tmp;

	tmp = mini()->exp;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
}

void	export_(void)
{
	ft_lstsort(&mini()->exp);
	print_exp();
}
