/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:59:58 by malourei          #+#    #+#             */
/*   Updated: 2025/03/06 20:35:06 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include <stdio.h>

void	validate_args(t_cmd *argv, int *cmd_argc)
{
	t_cmd	*node;
	int		i;

	node = argv;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	*cmd_argc = i;
}

void	count_pids(t_pipex *pipex, int argc)
{
	int	i;

	i = argc;
	pipex->pids = ft_calloc(sizeof(int), (size_t)argc);
	if (pipex->pids == NULL)
		return (perror("malloc1"), (void)argc);
	pipex->paths = ft_calloc(sizeof(char *), argc);
	if (pipex->paths == NULL)
		return (perror("malloc2"), free(pipex->pids), (void)argc);
	if (i > 1)
		i -= 1;
	pipex->fds = ft_calloc(sizeof(t_fds), i);
	if (pipex->fds == NULL)
		return (free(pipex->pids), free(pipex->paths), perror("malloc3"),
			(void)argc);
}

void	free_env(char **strs)
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

void	multi_pipe_help(t_cmd *node, t_pipex *pipex, int i)
{
	if (node->read < 3)
	{
		if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
			return (perror("dup10"), (void)i);
	}
	if (node->w < 3)
	{
		if (dup2(pipex->fds[i].fd[1], STDOUT_FILENO) < 0)
			return (perror("dup11"), (void)i);
	}
}
