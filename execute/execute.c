/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by malourei          #+#    #+#             */
/*   Updated: 2025/03/04 16:57:54 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "execute.h"

static bool	ret(t_cmd *cmd)
{
	if (!cmd)
		return (true);
	return (mini()->exit_code = 1, ft_putstr_fd("Error near >", 2), false);
}

static bool	check_redirects(t_cmd **cmd)
{
	t_cmd	*temp;

	temp = *cmd;
	while (temp)
	{
		if (temp->fd)
		{
			if (!change_fd(&temp))
				return (false);
		}
		temp = temp->next;
	}
	return (ret(temp));
}

static bool	bad_files(t_fd *f)
{
	t_fd	*fl;

	if (!f)
		return (false);
	fl = f;
	while (fl)
	{
		if (fl->fd == -1)
			return (mini()->exit_code = 2, true);
		fl = fl->next;
	}
	return (false);
}

void	execute(void)
{
	change_cmd(&mini()->cmd);
	check_redirects(&mini()->cmd);
	if (ft_cmdlst_len(&mini()->cmd) == 1 && bad_files(mini()->cmd->fd))
		return ;
	else if (ft_cmdlst_len(&mini()->cmd) == 1 && is_builtin(mini()->cmd->cmd))
		execute_builtin(mini()->cmd, mini()->cmd->w, 0);
	else
		pipex();
}
