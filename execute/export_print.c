/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:18:27 by malourei          #+#    #+#             */
/*   Updated: 2025/02/27 23:25:26 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static void	print_exp(int fd)
{
	t_list	*tmp;

	tmp = mini()->exp;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putendl_fd(tmp->content, fd);
		tmp = tmp->next;
	}
}

void	export_print(int fd)
{
	mini()->exit_code = 0;
	ft_lstsort(&mini()->exp);
	print_exp(fd);
}
