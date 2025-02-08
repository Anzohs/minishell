/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:31:13 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/08 20:39:10 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	env_execute(int fd)
{
	t_list	*tmp;

	tmp = mini()->env;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, fd);
		tmp = tmp->next;
	}
}
