/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by malourei          #+#    #+#             */
/*   Updated: 2025/02/08 20:42:35 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "execute.h"

static bool	ret(t_cmd *cmd)
{
	if (!cmd)
		return (true);
	return (ft_putstr_fd("Error near >", 2), false);
}

static int get_last_fd(t_fd *fd)
{
	t_fd	*f;
	int		file;

	f = fd;
	file = 0;
	while (f)
	{
		if (f->type == CREATE || f->type == APPEND)
			file = f->fd;
		f = f->next;
	}
	return (file);
}

static void	change_fd(t_cmd **cmd)
{
	t_fd	*f;

	f = (*cmd)->fd;
	while (f)
	{
		if (f->type == CREATE)
			f->fd = open(f->name, O_CREAT | O_TRUNC, 0644);
		if (f->type == APPEND)
			f->fd = open(f->name, O_CREAT | O_WRONLY | O_APPEND, 0664);
		f = f->next;
	}
	(*cmd)->w = get_last_fd((*cmd)->fd);
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
	{
		if (!ft_strcmp(mini()->cmd->cmd, "cd"))
			return (cd_execute(mini()->cmd->matrix, mini()->cmd->w));
		if (!ft_strcmp(mini()->cmd->cmd, "pwd"))
			return (pwd_execute(mini()->cmd->w));
		if (!ft_strcmp(mini()->cmd->cmd, "env"))
			return (env_execute(mini()->cmd->w));
		if (!ft_strcmp(mini()->cmd->cmd, "unset"))
			return (unset_execute(mini()->cmd));
		if (!ft_strcmp(mini()->cmd->cmd, "echo"))
			return (echo_exec(mini()->cmd));
		if (!ft_strcmp(mini()->cmd->cmd, "export"))
		{
			if (*mini()->cmd->arg)
				return (export_built(mini()->cmd->matrix));
			return (export_print(mini()->cmd->w));
		}
		else
			printf("nao e cd\n");
	}
	else
		pipex();
}
