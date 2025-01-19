/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/19 18:47:40 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static bool	is_builtin(t_string s)
{
	return (!ft_strcmp(s, "echo") || \
		!ft_strcmp(s, "cd") || \
		!ft_strcmp(s, "export") || \
		!ft_strcmp(s, "unset") || \
		!ft_strcmp(s, "env") || \
		!ft_strcmp(s, "pwd"));
}

void	execute(void)
{
	if (!mini()->cmd->cmd || !*mini()->cmd->cmd)
		return ;
	if (ft_cmdlst_len(&mini()->cmd) == 1 && is_builtin(mini()->cmd->cmd))
	{
		if (!ft_strcmp(mini()->cmd->cmd, "cd"))
			cd_execute();
		else
			printf("nao e cd\n");
	}
	else
		printf("demasiado grande\n");
}
