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

t_string	*fusion_strs(void)
{
	t_string	*matrix;
	int			i;

	matrix = ft_calloc(ft_count(mini()->commands->entry.args) + 2, sizeof(t_string));
	matrix[0] = ft_strdup(mini()->commands->entry.key);
	i = 0;
	while (mini()->commands->entry.args[i])
	{
		//printf("arg[%d]: %s\n",i , mini()->commands->entry.args[i]);
		matrix[i + 1] = ft_strdup(mini()->commands->entry.args[i]);
		i++;
	}
	matrix[i + 1] = NULL;
	return (matrix);
}

void	execve2(const char *path, t_node *node, char *const envp[], t_pipex *pipex)
{
	char	**argv;
	char	*str_join;
	char	*str_join_2;

	(void)pipex;
	argv = fusion_strs();
	execve(path, argv, envp);
	if (execve(path, argv, envp) == -1)
	{
		free_env(argv);
		return ;
	}
	//free_env(argv);
}

void	ft_child_one(t_pipex *pipex, char **env, char *cmd_path, t_node *node)
{
	if (dup2(pipex->fds[0].fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup1");
		return ;
	}
	ft_close_all_1(pipex);
	execve2(cmd_path, node, env, pipex);
}

void	ft_child_one_martelado(t_pipex *pipex, char **env, char *cmd_path, t_node *node)
{
	int	i;
	t_node	*tmp;

	tmp = node;
	i = -1;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	if (access(cmd_path, F_OK) != 0)
	{
		write(2, "command not found\n", 18);
		return ;
	}
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
	{
		perror("pid2");
		free(pipex->pids);
		return ;
	}
	if (pipex->pids[i] == 0)
	{
		if (dup2(pipex->fds[i].fd[0], STDIN_FILENO) < 0)
		{
			perror("dup2");
			return ;
		}
		ft_close_all_p(pipex);
		execve2(cmd_path, tmp, env, pipex);
	}
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
