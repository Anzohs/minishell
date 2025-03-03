/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:24:14 by malourei          #+#    #+#             */
/*   Updated: 2025/03/01 23:58:12 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"
#include <unistd.h>

t_string	*fusion_strs(t_cmd *cmd)
{
	t_string	*matrix;
	int			i;

	matrix = ft_calloc(matrix_len(cmd->matrix) + 2, sizeof(t_string));
	matrix[0] = ft_strdup(cmd->cmd);
	i = 0;
	while (cmd->matrix[i])
	{
		matrix[i + 1] = ft_strdup(cmd->matrix[i]);
		i++;
	}
	matrix[i + 1] = NULL;
	return (matrix);
}

void	execve2(const char *path, t_cmd *node, char *const envp[])
{
	char	**argv;

	argv = fusion_strs(node);
	if (execve(path, argv, envp) == -1)
		return (free_env(argv), (void)argv);
}

void	child_one(t_pipex *pipex, char **env, char *cmd_path, t_cmd *node)
{
	check_ridirects(node, cmd_path);
	if (node->w < 3)
	{
		if (dup2(pipex->fds[0].fd[1], STDOUT_FILENO) < 0)
			return (perror("dup4"), (void)pipex);
	}
	if (is_builtin(node->cmd))
		return (clean_all(pipex), execute_builtin(node, STDOUT_FILENO, 1),
			(void)1);
	ft_close_all_1(pipex);
	ft_close_all_files(node);
	execve2(cmd_path, node, env);
}

void	ft_parent(t_pipex *pipex)
{
	int	i;

	i = -1;
	ft_close_all_p(pipex);
	while (++i < pipex->cmd_argc)
		waitpid(pipex->pids[i], NULL, 0);
	clean_all(pipex);
}
