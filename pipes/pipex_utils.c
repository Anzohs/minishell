/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:24:14 by malourei          #+#    #+#             */
/*   Updated: 2024/12/30 21:22:02 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


// Estou a ver os processos ft_child_one

void	execve2(const char *path, t_node *node, char *const envp[])
{
	char	*argv[2];

	argv[0] = node->entry.key;
	argv[1] = node->entry.value;
	if (execve(path, argv, envp) == -1)
	{
		printf("Error: Comando invalido %s!\n", path);
		return ;
	}
}

void	ft_child_one(t_pipex *pipex, char **env, char *cmd_path, t_node *node)
{
	if (dup2(pipex->fds[0].fd[0], STDIN_FILENO) < 0)
	{

	}
	if (dup2(pipex->fds[1].fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		return ;
	}
	ft_close_all_1(pipex);
	execve2(cmd_path, node, env);
}

void	ft_child_two(t_pipex *pipex, char **env, char *cmd_path, t_node *node)
{
	if (dup2(pipex->fds[pipex->cmd_argc - 1].fd[0], STDIN_FILENO) < 0)
	{
		perror("dup3");
		return ;
	}
	ft_close_all_p(pipex);
	execve2(cmd_path, node, env);
}

void	ft_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	ft_close_all_p(pipex);
	while (i < pipex->argc)
	{
		waitpid(pipex->pids[i], NULL, 0);
		i++;
	}
	clean_all(pipex);
}
