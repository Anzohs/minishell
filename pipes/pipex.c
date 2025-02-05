/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:24:53 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/05 18:57:11 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"
#include "../mini_struct/mini.h"
#include <unistd.h>

static void	start_pipe_1(t_pipex *pipex, \
				t_mini *mini, size_t len, t_cmd *argv2)
{
	int	i;

	i = 0;
	(void)len;
	(void)mini;
	if (pipe(pipex->fds[0].fd) < 0)
	{
		perror("pipe");
		return ;
	}
	if (access(pipex->paths[0], F_OK) != 0)
	{
		write(2, "command not found\n", 18);
		return ;
	}
	pipex->pids[i] = fork();
	if (pipex->pids[i] == 0)
	{
		if (pipex->is_doc == 0)
			ft_child_one(pipex, pipex->env_path, pipex->paths[0], argv2);
	}
	if (pipex->pids[i] < 0)
	{
		perror("pid");
		free(pipex->pids);
		return ;
	}
}

static void	start_multi2_pipe(t_pipex *pipex, \
				t_mini *mini, int i, char *cmd_path, t_cmd *node)
{
	(void)mini;
	if (access(cmd_path, F_OK) != 0)
	{
		printf("command not found\n");
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
		if (pipex->pids[i - 1])
		{
			if (dup2(pipex->fds[i - 1].fd[0], STDIN_FILENO) < 0)
			{
				perror("dup5");
				return ;
			}
		}
		if (dup2(pipex->fds[i].fd[1], STDOUT_FILENO) < 0)
		{
			perror("dup6");
			return ;
		}
		ft_close_all_m(pipex, i);
		execve2(cmd_path, node, pipex->env_path, pipex);
	}
}

static void	one_cmd(t_pipex *pipex, t_mini *mini)
{
	if (access(pipex->path2, F_OK) != 0)
	{
		pipex->cmd_argc -= 1;
		printf("command not found: %s\n", mini->cmd->cmd);
		return ;
	}
	if (pipe(pipex->fds[0].fd) < 0)
	{
		perror("pipe");
		return ;
	}
	pipex->pids[0] = fork();
	if (pipex->pids[0] < 0)
	{
		perror("pid");
		free(pipex->pids);
		return ;
	}
	if (pipex->pids[0] == 0)
	{
		ft_close(pipex->fds[0].fd[1]);
		if (dup2(pipex->fds[0].fd[1], STDOUT_FILENO) < -1)
		{
			write(2, "DUP8\n", 5);
			return ;
		}
		ft_close(pipex->fds[0].fd[0]);
		execve2(pipex->path2, mini->cmd, pipex->env_path, pipex);
	}
	return ;
}

static void	start_multi_pipe(t_pipex *pipex, t_mini *mini, int argc, t_cmd *n)
{
	int		i;
	int		j;
	t_cmd	*node;

	if (argc == 1)
	{
		one_cmd(pipex, mini);
		return ;
	}
	start_pipe_1(pipex, mini, argc, n);
	node = n;
	i = 0;
	j = argc - 1;
	while (++i < j && n)
	{
		node = node->next;
		if (pipe(pipex->fds[i].fd) < 0)
		{
			perror("pipe2");
			return ;
		}
		start_multi2_pipe(pipex, mini, i, pipex->paths[i], node);
	}
	ft_child_one_martelado(pipex, pipex->env_path, pipex->path2, n);
}

char	**get_strs_envs(t_pipex *pipex)
{
	char	*str;
	char	**strs;
	char	*str2;

	str = ft_lsthas(mini()->env, "PATH=");
	if (!*str)
		return (NULL);
	str2 = ft_strjoin("PATH", str);
	if (!str2)
		return (NULL);
	pipex->env_path = ft_calloc(2, sizeof(char *));
	if (!pipex->env_path)
		return (NULL);
	pipex->env_path[0] = str2;
	pipex->env_path[1] = NULL;
	str++;
	strs = ft_split(str, ':');
	return (strs);
}

void	pipex(t_mini *min, t_cmd *comands)
{
	t_pipex	pipex;

	pipex = (t_pipex){0};
	(void)min;
	(void)comands;
	validate_args(mini()->cmd, &pipex.cmd_argc);
	count_pids(&pipex, pipex.cmd_argc);
	pipex.env = get_strs_envs(&pipex);
	if (!find_full_cmd(&pipex, mini(), mini()->cmd))
	{
		clean_all(&pipex);
		return ;
	}
	start_multi_pipe(&pipex, mini(), ft_lstsize((t_list *)mini()->cmd), mini()->cmd);
	ft_parent(&pipex);
}
