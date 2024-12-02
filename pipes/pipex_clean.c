/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:12:01 by malourei          #+#    #+#             */
/*   Updated: 2024/09/24 23:38:01 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_path(t_pipex *pipex, char *path)
{
	if (path == NULL)
	{
		write(2, "Error: NAO EXISTE CMD!\n", 23);
		clean_pointer(pipex->env);
		clean_pointer(pipex->paths);
		free(pipex->pids);
		free(pipex->fds);
		exit(1);
	}
}

void	clean_pointer(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	clean_null_env(t_pipex *pipex)
{
	free(pipex->paths);
	free(pipex->pids);
	free(pipex->fds);
}

void	clean_all(t_pipex *pipex)
{
	clean_pointer(pipex->cmd2);
	clean_pointer(pipex->env);
	clean_pointer(pipex->paths);
	free(pipex->path2);
	free(pipex->pids);
	free(pipex->fds);
}
