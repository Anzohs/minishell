/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:24:53 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/03 20:36:43 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	ft_clean_path(t_pipex *pipex, char *path)
{
	if (path == NULL)
	{
		write(2, "Error: NAO EXISTE CMD!\n", 23);
		clean_pointer(pipex->env);
		clean_pointer(pipex->paths);
		free(pipex->pids);
		free(pipex->fds);
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
	//clean_pointer(pipex->cmd2);
	clean_pointer(pipex->env);
	clean_pointer(pipex->paths);
	free(pipex->path2);
	free(pipex->pids);
	free(pipex->fds);
}
