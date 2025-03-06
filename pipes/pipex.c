/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:14:26 by malourei          #+#    #+#             */
/*   Updated: 2025/03/06 20:36:13 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "../signals/ft_signals.h"
#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>

static void	start_pipe_1(t_pipex *pipex, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (pipe(pipex->fds[0].fd) < 0)
		return (perror("pipe"), (void)i);
	if (!is_builtin(cmd->cmd) && access(pipex->paths[0], F_OK) != 0)
		return (ft_putendl_fd("command not found", STDERR_FILENO));
	if (!good_files(cmd) || !*cmd->cmd)
		return ;
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (perror("pid"), free(pipex->pids), (void)i);
	if (pipex->pids[i] == 0)
	{
		mini()->sig = 3;
		load_signals();
		child_one(pipex, pipex->env, pipex->paths[0], cmd);
	}
}

static void	start_multi2_pip(t_pipex *pipex, int i, char *cmd_path, t_cmd *node)
{
	if (!is_builtin(node->cmd) && access(cmd_path, F_OK) != 0)
		return (ft_putendl_fd("command not found", STDERR_FILENO), (void)i);
	if (!good_files(node) || !*node->cmd)
		return ;
	check_command(node, cmd_path);
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
		return (perror("pid"), free(pipex->pids), (void)i);
	if (pipex->pids[i] == 0)
	{
		check_ridirects(node, cmd_path);
		multi_pipe_help(node, pipex, i);
		if (is_builtin(node->cmd))
			return (mini()->pipex = pipex, mini()->pipes = i,
				execute_builtin(node, STDOUT_FILENO, 1), (void)i);
		ft_close_all_m(pipex, i);
		ft_close_all_files(mini()->cmd);
		execve2(cmd_path, node, pipex->env);
	}
}

static void	one_cmd(t_pipex *pipex, t_mini *mini)
{
	if (ft_strcmp("", pipex->path2) == 0)
		return (pipex->cmd_argc -= 1, printf("%s : Command not found\n",
				mini->cmd->cmd), (void)pipex);
	if (pipe(pipex->fds[0].fd) < 0)
		return (perror("pipe"), (void)pipex);
	if (!*mini->cmd->cmd)
		return (ft_close_all_1(pipex));
	if (!check_command(mini->cmd, pipex->path2))
		return (ft_close_all_1(pipex), (void)pipex);
	pipex->pids[0] = fork();
	if (pipex->pids[0] < 0)
		return (perror("pid"), free(pipex->pids), (void)pipex);
	if (pipex->pids[0] == 0)
	{
		check_ridirects(mini->cmd, pipex->path2);
		if (is_builtin(mini->cmd->cmd))
			return (mini->pipex = pipex,
				execute_builtin(mini->cmd, STDOUT_FILENO, 1), (void)pipex);
		ft_close_all_1(pipex);
		ft_close_all_files(mini->cmd);
		execve2(pipex->path2, mini->cmd, pipex->env);
	}
	return ;
}

static void	start_multi_pipe(t_pipex *pipex, t_mini *mini, int argc, t_cmd *n)
{
	int		i;
	int		j;
	t_cmd	*node;

	if (argc == 1)
		return (one_cmd(pipex, mini), (void)argc);
	start_pipe_1(pipex, n);
	node = n;
	i = 0;
	j = argc - 1;
	while (++i < j && n)
	{
		node = node->next;
		if (pipe(pipex->fds[i].fd) < 0)
			return (perror("pipe2"), (void)i);
		start_multi2_pip(pipex, i, pipex->paths[i], node);
	}
	child_two(pipex, pipex->env, pipex->path2, n);
}

void	pipex(void)
{
	t_pipex	pipex;

	pipex = (t_pipex){0};
	if (!check_per_cmd(mini()->cmd))
		return (g_sig = 0, (void)pipex);
	validate_args(mini()->cmd, &pipex.cmd_argc);
	count_pids(&pipex, pipex.cmd_argc);
	pipex.env = ft_lsttomatrix(mini()->env);
	get_strs_envs(&pipex);
	mini()->sig = 3;
	mini()->exit_code = 0;
	load_signals();
	if (!find_full_cmd(&pipex, mini()->cmd))
		return (clean_all(&pipex), mini()->sig = 1, load_signals());
	start_multi_pipe(&pipex, mini(), ft_cmdsize(mini()->cmd), mini()->cmd);
	ft_parent(&pipex);
	return (mini()->sig = 1, load_signals());
}
