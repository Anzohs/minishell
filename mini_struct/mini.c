/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:54:56 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/05 00:09:10 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	start_tmini(t_mini *mini)
{
	mini->start = 1;
	mini->pipex = NULL;
	//rl_catch_signals = 1;
}

t_mini	*mini(void)
{
	static t_mini	m;

	if (!m.start)
		start_tmini(&m);
	return (&m);
}
