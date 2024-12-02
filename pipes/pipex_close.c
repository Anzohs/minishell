/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:42:55 by malourei          #+#    #+#             */
/*   Updated: 2024/10/04 19:48:06 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int fd)
{
	if (fd > 0 && fd != STDERR_FILENO && fd != STDIN_FILENO
		&& fd != STDOUT_FILENO)
		close (fd);
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
	if (pipex->is_doc == 0)
		ft_close(pipex->in_file);
	ft_close(pipex->out_file);
}

void	ft_close_all_1(t_pipex *pipex)
{
	ft_close(pipex->fds[0].fd[0]);
	ft_close(pipex->fds[0].fd[1]);
	if (pipex->is_doc == 0)
		ft_close(pipex->in_file);
	ft_close(pipex->out_file);
}

void	ft_close_all_p(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->argc - 1))
	{
		ft_close(pipex->fds[i].fd[0]);
		ft_close(pipex->fds[i].fd[1]);
		i++;
	}
	if (pipex->is_doc == 0)
		ft_close(pipex->in_file);
	ft_close(pipex->out_file);
}
