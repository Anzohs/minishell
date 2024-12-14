/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tmini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:40:18 by hladeiro          #+#    #+#             */
/*   Updated: 2024/12/14 17:24:01 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tmini(t_mini *m)
{
	if (m->c)
		free(m->c);
	if (m->readline)
		free(m->readline);
	if (m->ht)
		hdestroy(m->ht);
	if (m->commands)
		free_node(m->commands);
	if (m->super_env)
		free_env(m->super_env);
}
