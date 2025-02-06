/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by malourei          #+#    #+#             */
/*   Updated: 2025/02/04 21:39:20 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "../mini_struct/mini.h"

void	execute(void)
{
	if (!mini()->cmd->cmd || !*mini()->cmd->cmd)
		return ;
	if (ft_cmdlst_len(&mini()->cmd) == 1 && is_builtin(mini()->cmd->cmd))
	{
		if (!ft_strcmp(mini()->cmd->cmd, "cd"))
			return (cd_execute(mini()->cmd->matrix));
		if (!ft_strcmp(mini()->cmd->cmd, "pwd"))
			return (pwd_execute());
		if (!ft_strcmp(mini()->cmd->cmd, "export"))
		{
			if (*mini()->cmd->arg)
				return ;
			return (export_print());
		}
		else
			printf("nao e cd\n");
	}
	else
		pipex();
}
