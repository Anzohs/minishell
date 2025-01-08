/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_val_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:42:55 by malourei          #+#    #+#             */
/*   Updated: 2024/12/30 19:37:00 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static char	*find_cmd(char *cmd, char **path)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (path[i] && cmd)
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	return (NULL);
}

static t_string	get_command(t_node *n, int i)
{
	t_node	*tmp;
	int		j;

	tmp = n;
	j = 0;
	while (j < i && tmp)
	{
		j++;
		tmp = tmp->next;
	}
	if (!tmp)
		return (NULL);
	return (tmp->entry.key);
}

static bool	get_all_path(t_pipex *pipex, t_node *node)
{
	int	i;
	int	n;

	i = 0;
	n = node_len(node) - 1;
	while (i < n)
	{
		pipex->paths[i] = find_cmd(get_command(node, i), pipex->env);
		if (!pipex->paths[i])
			return (false);
		ft_clean_path(pipex, pipex->paths[i]);
		i++;
	}
	pipex->paths[i] = NULL;
	pipex->path2 = find_cmd(get_command(node, n), pipex->env);
	if (!pipex->path2)
		return (false);
	ft_clean_path(pipex, pipex->path2);
	return (true);
}

bool	find_full_cmd(t_pipex *pipex, t_mini *mini, t_node *node)
{
	int		i;
	char	*tmp;

	i = get_index(mini->super_env, "PATH=", 5);
	if (i == -1)
	{
		perror("Error: No Path!");
		clean_null_env(pipex);
		return (false);
	}
	pipex->env = ft_split(mini->super_env[i], ':');
	tmp = ft_strdup(pipex->env[0] + 5);
	free(pipex->env[0]);
	pipex->env[0] = ft_strdup(tmp);
	free(tmp);
	return (get_all_path(pipex, node));
	//pipex->cmd2 = (char **)get_command(node, node_len(node) - 1);
}
