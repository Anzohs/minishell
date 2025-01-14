/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:53:19 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/14 20:04:33 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



bool	clean_node(t_node *n)
{
	t_node	*tmp;
	int		i;

	tmp = mini()->commands;
	i = -1;
	while (tmp)
	{
		parse_node(&tmp);
		clean_quotes(&tmp->entry.key);
		while (tmp->entry.args[++i])
			clean_quotes(&tmp->entry.args[i]);
		tmp = tmp->next;
		i = -1;
	}
	return (true);
}
