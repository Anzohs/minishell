/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:42:55 by malourei          #+#    #+#             */
/*   Updated: 2025/02/13 22:38:08 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	ft_close(int fd)
{
	if (fd > 0 && fd != STDERR_FILENO && fd != STDIN_FILENO
		&& fd != STDOUT_FILENO)
		close (fd);
}

void	ft_close_file(t_cmd *cmd)
{
	if (cmd->fd)
	{
		if (cmd->w >= 3)
			ft_close(cmd->w);
		else if (cmd->read >= 3)
			ft_close(cmd->read);
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

void	ft_close_all_m(t_pipex *pipex, int i)
{
	int	k;

	k = 0;
	while (k <= i)
	{
		ft_close(pipex->fds[k].fd[0]);
		ft_close(pipex->fds[k].fd[1]);
		k++;
	}
}

void	ft_close_all_1(t_pipex *pipex)
{
	//ft_close(mini()->cmd->w);
	ft_close(pipex->fds[0].fd[0]);
	ft_close(pipex->fds[0].fd[1]);
}

void	ft_close_all_p(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd_argc == 1)
		ft_close_all_1(pipex);
	while (i < (pipex->cmd_argc - 1))
	{
		ft_close(pipex->fds[i].fd[0]);
		ft_close(pipex->fds[i].fd[1]);
		i++;
	}
}
