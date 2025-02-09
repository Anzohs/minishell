/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:31:13 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/09 18:04:38 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	unset_execute(t_cmd *cmd)
{
	int		i;
	t_list	*env_node;
	t_list	*exp_node;

	if (!cmd->matrix || !*cmd->matrix[0])
		return ;
	i = -1;
	while (cmd->matrix[++i])
	{
		env_node = ft_lstgetlst(&mini()->env, cmd->matrix[i]);
		if (env_node)
			ft_lstpop(&mini()->env, env_node);
		exp_node = ft_lstgetlst(&mini()->exp, cmd->matrix[i]);
		if (exp_node)
			ft_lstpop(&mini()->exp, exp_node);
	}
}
