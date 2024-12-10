/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:24:14 by malourei          #+#    #+#             */
/*   Updated: 2024/09/24 23:37:54 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execve2(const char *path, t_node *node, char *const envp[])
{
	char	*argv[2];

	argv[0] = node->entry.key;
	argv[1] = node->entry.value;
	if (execve(path, argv, envp) == -1)
	{
		printf("Error: Comando invalido %s!\n", path);
		exit(1);
	}
}

void	ft_child_one(t_pipex *pipex, char **env, char *cmd_path, t_node *node)
{
	if (dup2(pipex->in_file, STDIN_FILENO) < 0)
	{
		perror("dup1");
		exit(1);
	}
	if (dup2(pipex->fds[0].fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(1);
	}
	ft_close_all_1(pipex);
	execve2(cmd_path, node, env);
	exit(0);
}

void	ft_child_two(t_pipex *pipex, char **env, char *cmd_path)
{
	if (dup2(pipex->fds[pipex->argc - 2].fd[0], STDIN_FILENO) < 0)
	{
		perror("dup3");
		exit(1);
	}
	if (dup2(pipex->out_file, STDOUT_FILENO) < 0)
	{
		perror("dup4");
		exit(1);
	}
	ft_close_all_p(pipex);
	execve2(cmd_path, pipex->cmd2, env);
	exit(0);
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
