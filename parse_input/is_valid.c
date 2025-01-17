/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:54:17 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/16 21:07:26 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

bool	is_valid(void)
{
	t_cmd	*lst;

	lst = mini()->cmd;
	while (lst)
	{
		if (!closed_quotes(lst->cmd) || !closed_quotes(lst->arg))
		{
			perror("sintax error quotes");
			return (false);
		}
		if (!lst->cmd || !*lst->cmd)
		{
			perror("sintax error |");
			return (false);
		}
		lst = lst->next;
	}
	return (true);
}
