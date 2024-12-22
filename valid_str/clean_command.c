/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:41:45 by hladeiro          #+#    #+#             */
/*   Updated: 2024/12/22 16:02:08 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	clean_command(t_mini *m)
{
	t_node	*tmp;

	tmp = m->commands;
	while (tmp)
	{
		if (!closed_quotes(tmp->entry.key) || !closed_quotes(tmp->entry.value))
		{
			printf("Error: open quotes!\n");
			return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}
