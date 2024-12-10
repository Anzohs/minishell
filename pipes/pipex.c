/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:22:58 by malourei          #+#    #+#             */
/*   Updated: 2024/09/24 23:39:24 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../minishell.h"
#include <unistd.h>

static void	start_pipe_1(t_pipex *pipex, char **env, size_t len,t_node *argv2)
{
	int	i;

	i = len - 1;
	if (pipe(pipex->fds[0].fd) < 0)
	{
		perror("pipe");
		exit(1);
	}
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
	{
		perror("pid");
		free(pipex->pids);
		exit(1);
	}
	if (pipex->pids[i] == 0)
	{
		if (pipex->is_doc == 0)
			ft_child_one(pipex, env, pipex->paths[0]);
		else
			ft_child_doc_one(pipex, env, pipex->paths[0]);
	}
	clean_pointer(pipex->cmd1);
}

static void	start_pipe_2(t_pipex *pipex, char **env)
{
	pipex->pids[pipex->argc - 1] = fork();
	if (pipex->pids[pipex->argc - 1] < 0)
	{
		perror("pid2");
		exit(1);
	}
	if (pipex->pids[pipex->argc - 1] == 0)
		ft_child_two(pipex, env, pipex->path2);
}

static void	start_multi2_pipe(t_pipex *pipex, t_mini *mini, int i, char *cmd_path)
{
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
	{
		perror("pid");
		free(pipex->pids);
		exit(1);
	}
	if (pipex->pids[i] == 0)
	{
		if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
		{
			perror("dup1");
			exit(1);
		}
		if (dup2(pipex->fds[i].fd[1], STDOUT_FILENO) < 0)
		{
			perror("dup2");
			exit(1);
		}
		ft_close_all_m(pipex, i);
		execve2(cmd_path, mini->commands, mini->super_env);
	}
}

static void	start_multi_pipe(t_pipex *pipex, char **env, int argc, t_node *n)
{
	int	i;
	int	j;

	start_pipe_1(pipex, env, node_len(n), n);
	i = 0;
	j = node_len(n);
	while (++i < j)
	{
		if (pipe(pipex->fds[i].fd) < 0)
		{
			perror("pipe2");
			exit(1);
		}
		//free_current(n);
		start_multi2_pipe(pipex, env, i, pipex->paths[i]);
	}
}

void	pipex(t_mini *mini, t_node *comands)
{
	t_pipex	pipex;

	pipex = (t_pipex){0};
	validate_args(comands, &pipex.cmd_argc);
	count_pids(&pipex, node_len(comands) - pipex.cmd_argc);
	find_full_cmd(&pipex, mini, comands);
	if (ft_strncmp(comands->entry.key, "here_doc", 8) == 0)
		start_here_doc(&pipex, comands);
	else
		start_in_file(&pipex);
	pipex.out_file = open(".outfile_pipex", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex.out_file < 0)
	{
		perror("ErrorOUT");
		ft_close(pipex.in_file);
		unlink(".infile_pipex");
		clean_all(&pipex);
		return ;
	}
	//continuar aqui
	start_multi_pipe(&pipex, mini->super_env, node_len(comands), comands);
	// tenho que falar com o ze sobre o commands e as envs porque passo a mini em vez do envs
	start_pipe_2(&pipex, env);
	ft_parent(&pipex);
}
