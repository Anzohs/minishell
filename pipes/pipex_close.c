/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:42:55 by malourei          #+#    #+#             */
/*   Updated: 2025/02/26 22:36:42 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	ft_close(int fd)
{
	if (fd > 0 && fd != STDERR_FILENO && fd != STDIN_FILENO
		&& fd != STDOUT_FILENO)
		close(fd);
}

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
