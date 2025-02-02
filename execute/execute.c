/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/02 17:46:54 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	execute(void)
{
	if (!mini()->cmd->cmd || !*mini()->cmd->cmd)
		return ;
	if (ft_cmdlst_len(&mini()->cmd) == 1 && is_builtin(mini()->cmd->cmd))
	{
		if (!ft_strcmp(mini()->cmd->cmd, "cd"))
			return (cd_execute());
		if (!ft_strcmp(mini()->cmd->cmd, "pwd"))
			return (pwd_execute());
		else
			printf("nao e cd\n");
	}
	else
		printf("Long string \n");
}
