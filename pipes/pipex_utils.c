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

void	execve2(const char *path, t_node *node, char *const envp[])
{
	char	**argv;
	char	*str_join;
	char	*str_join_2;

	str_join = ft_strjoin(node->entry.key, " ");
	str_join_2 = ft_strjoin(str_join, ((char *)node->entry.value));
	free(str_join);
	argv = ft_split(str_join_2, ' ');
	free(str_join_2);
	if (execve(path, argv, envp) == -1)
	{
		printf("Error: Comando invalido %s!\n", path);
		return ;
	}
	free_env(argv);
}

void	ft_child_one(t_pipex *pipex, char **env, char *cmd_path, t_node *node)
{
	if (dup2(pipex->fds[0].fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup1");
		return ;
	}
	ft_close_all_1(pipex);
	execve2(cmd_path, node, env);
}

void	ft_child_one_martelado(t_pipex *pipex, char **env, char *cmd_path, t_node *node)
{
	int	i;
	t_node	*tmp;

	tmp = node;
	while(tmp->next)
		tmp = tmp->next;
	i = 1;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
	{
		perror("pid2");
		free(pipex->pids);
		return ;
	}
	if (pipex->pids[i] == 0)
	{
		if (dup2(pipex->fds[0].fd[0], STDIN_FILENO) < 0)
		{
			perror("dup2");
			return ;
		}
		ft_close_all_1(pipex);
		execve2(cmd_path, tmp, env);
	}
}

/* void	ft_child_one_cmd(t_pipex *pipex, char **env, char *cmd_path, t_node *n)
{

} */


void	ft_child_two(t_pipex *pipex, char **env, char *cmd_path, t_node *node)
{
	if (dup2(pipex->fds[pipex->cmd_argc - 1].fd[0], STDIN_FILENO) < 0)
	{
		perror("dup3");
		return ;
	}
	ft_close_all_1(pipex);
	execve2(cmd_path, node, env);
}

void	ft_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	ft_close_all_p(pipex);
	while (i < pipex->cmd_argc)
	{
		waitpid(pipex->pids[i], NULL, 0);
		i++;
	}
	clean_all(pipex);
}
