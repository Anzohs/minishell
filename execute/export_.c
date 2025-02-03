/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:18:27 by malourei          #+#    #+#             */
/*   Updated: 2025/02/03 21:23:08 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

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
