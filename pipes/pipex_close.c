/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:42:55 by malourei          #+#    #+#             */
/*   Updated: 2025/03/01 20:41:50 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"

void	ft_close(int fd)
{
	if (fd > 0 && fd != STDERR_FILENO && fd != STDIN_FILENO
		&& fd != STDOUT_FILENO)
		close(fd);
}

void	ft_close_all_m(t_pipex *pipex, int i, t_cmd *node)
{
	int	k;

	k = 0;
	while (k <= i)
	{
		ft_close(pipex->fds[k].fd[0]);
		ft_close(pipex->fds[k].fd[1]);
		k++;
	}
	ft_close_all_files(node);
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
