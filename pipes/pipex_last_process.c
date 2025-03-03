/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_last_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:56:35 by malourei          #+#    #+#             */
/*   Updated: 2025/03/02 00:01:33 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static t_cmd	*child_two_help_2(t_cmd *node, int *i)
{
	t_cmd	*tmp;

	tmp = node;
	*i = 0;
	while (tmp->next)
	{
		*i = *i + 1;
		tmp = tmp->next;
	}
	return (tmp);
}

void	child_two(t_pipex *pipex, char **env, char *cmd_path, t_cmd *node)
{
	int		i;
	t_cmd	*tmp;

	tmp = child_two_help_2(node, &i);
	if (!check_command(tmp, cmd_path))
		return ;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (perror("pid2"), free(pipex->pids), (void)cmd_path);
	if (pipex->pids[i] == 0)
	{
		check_ridirects(tmp, cmd_path);
		if (tmp->read < 3)
		{
			if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
				return (perror("dup69"), (void)cmd_path);
		}
		if (is_builtin(tmp->cmd))
			return (clean_all(pipex), execute_builtin(tmp, STDOUT_FILENO, 1),
				(void)i);
		return (ft_close_all_p(pipex), ft_close_all_files(node),
			execve2(cmd_path, tmp, env));
	}
}
