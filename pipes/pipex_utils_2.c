/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:59:58 by malourei          #+#    #+#             */
/*   Updated: 2025/02/05 19:04:24 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

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
	{
		perror("malloc1");
		return ;
	}
	pipex->paths = ft_calloc(sizeof(char *), argc);
	if (pipex->paths == NULL)
	{
		perror("malloc2");
		free(pipex->pids);
		return ;
	}
	if (i > 1)
		i -= 1;
	pipex->fds = ft_calloc(sizeof(t_fds), i);
	if (pipex->fds == NULL)
	{
		free(pipex->pids);
		free(pipex->paths);
		perror("malloc3");
		return ;
	}

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
