/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:22:58 by malourei          #+#    #+#             */
/*   Updated: 2024/12/30 21:22:03 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../minishell.h"
#include <unistd.h>

static void	start_pipe_1(t_pipex *pipex, t_mini *mini, size_t len, t_node *argv2)
{
	int	i;

	i = len - 1;
	if (pipe(pipex->fds[0].fd) < 0)
	{
		perror("pipe");
		return ;
	}
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
	{
		perror("pid");
		free(pipex->pids);
		return ;
	}
	if (pipex->pids[i] == 0)
	{
		if (pipex->is_doc == 0)
			ft_child_one(pipex, mini->super_env, pipex->paths[0], argv2);
		else
			ft_child_doc_one(pipex, mini->super_env, pipex->paths[0], mini->commands);
	}
}

static void	start_pipe_2(t_pipex *pipex, t_mini *m)
{
	pipex->pids[pipex->argc - 1] = fork();
	if (pipex->pids[pipex->argc - 1] < 0)
	{
		perror("pid2");
		return ;
	}
	if (pipex->pids[pipex->argc - 1] == 0)
		ft_child_two(pipex, m->super_env, pipex->path2, m->commands);
}

static void	start_multi2_pipe(t_pipex *pipex, t_mini *mini, int i, char *cmd_path)
{
	pipex->pids[i] = fork();
	if (pipex->pids[i] < 0)
	{
		perror("pid");
		free(pipex->pids);
		return ;
	}
	if (pipex->pids[i] == 0)
	{
		if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
		{
			perror("dup1");
			return ;
		}
		if (dup2(pipex->fds[i].fd[1], STDOUT_FILENO) < 0)
		{
			perror("dup2");
			return ;
		}
		ft_close_all_m(pipex, i);
		execve2(cmd_path, mini->commands, mini->super_env);
	}
}

static void	start_multi_pipe(t_pipex *pipex, t_mini *mini, int argc, t_node *n)
{
	int	i;
	int	j;

	start_pipe_1(pipex, mini, argc, n);
	i = 0;
	j = argc;
	while (++i < j && n)
	{
		n = n->next;
		if (pipe(pipex->fds[i].fd) < 0)
		{
			perror("pipe2");
			return ;
		}
		//free_current(mini->commands);
		//mini->current = n;
		start_multi2_pipe(pipex, mini, i, pipex->paths[i]);
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
	start_multi_pipe(&pipex, mini, node_len(comands), comands);
	// tenho que falar com o ze sobre o commands e as envs porque passo a mini em vez do envs
	start_pipe_2(&pipex, mini);
	ft_parent(&pipex);
}
