/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:59:58 by malourei          #+#    #+#             */
/*   Updated: 2024/11/14 17:59:31 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	validate_args(t_node *argv, int *cmd_argc)
{
	t_node	*node;
	int		i;

	node = argv;
	i = 0;
	while (node)
	{
		if (ft_strcmp(node->entry.key, "here_doc") == 0)
			*cmd_argc = i;
		node = node->next;
		i++;
	}
}

void	count_pids(t_pipex *pipex, int argc)
{
	pipex->pids = ft_calloc(sizeof(int), (size_t)argc);
	if (pipex->pids == NULL)
	{
		perror("malloc1");
		return ;
	}
	pipex->paths = ft_calloc(sizeof(char *), argc + 1);
	if (pipex->paths == NULL)
	{
		perror("malloc2");
		free(pipex->pids);
		return ;
	}
	pipex->fds = ft_calloc(sizeof(t_fds), (argc - 1));
	if (pipex->fds == NULL)
	{
		free(pipex->pids);
		free(pipex->paths);
		perror("malloc3");
		return ;
	}
}
