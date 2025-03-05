/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:41:16 by malourei          #+#    #+#             */
/*   Updated: 2025/03/05 00:23:33 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	ft_close_file(t_cmd *cmd)
{
	t_fd	*tmp;

	tmp = cmd->fd;
	while (tmp)
	{
		if (tmp->fd != -1 && tmp->fd > 2)
		{
			ft_close(tmp->fd);
			tmp->fd = 1;
		}
		if (cmd->w >= 3)
			ft_close(cmd->w);
		if (cmd->read >= 3)
			ft_close(cmd->read);
		tmp = tmp->next;
	}
}

void	ft_close_all_files(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		ft_close_file(tmp);
		tmp = tmp->next;
	}
}
