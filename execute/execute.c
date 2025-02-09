/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by malourei          #+#    #+#             */
/*   Updated: 2025/02/09 17:43:04 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include <fcntl.h>
#include "execute.h"

static bool	ret(t_cmd *cmd)
{
	if (!cmd)
		return (true);
	return (ft_putstr_fd("Error near >", 2), false);
}

static bool	check_redirects(t_cmd **cmd)
{
	t_cmd	*temp;

	temp = *cmd;
	while (temp)
	{
		if (temp->fd)
			change_fd(&temp);
		temp = temp->next;
	}
	return (ret(temp));
}

void	execute(void)
{
	if (!check_redirects(&mini()->cmd))
		return ;
	if (!mini()->cmd->cmd || !*mini()->cmd->cmd)
		return ;
	else if (ft_cmdlst_len(&mini()->cmd) == 1 && is_builtin(mini()->cmd->cmd))
		execute_builtin(mini()->cmd, mini()->cmd->w);
	else
		pipex();
}
