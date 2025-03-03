/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_val_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:42:55 by malourei          #+#    #+#             */
/*   Updated: 2025/02/18 21:23:06 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include <sys/types.h>
#include <dirent.h>

static char	*find_cmd(char *cmd, char **path)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	DIR 	*s;

	s = opendir(cmd);
	i = 0;
	if (s)
		return (free(s), ft_strdup(""));
	free(s);
	while (path && path[i] && cmd)
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK | X_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	if (!access(cmd, F_OK | X_OK))
		return (ft_strdup(cmd));
	return (ft_strdup(""));
}

static t_string	get_command(t_cmd *n, int i)
{
	t_cmd	*tmp;
	int		j;

	tmp = n;
	j = -1;
	while (++j < i && tmp)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (tmp->cmd);
}

static void	get_all_path(t_pipex *pipex, t_cmd *node)
{
	int	i;
	int	n;

	i = 0;
	n = ft_cmdsize(node) - 1;
	while (i < n)
	{
		pipex->paths[i] = find_cmd(get_command(node, i), pipex->env_path);
		ft_clean_path(pipex, pipex->paths[i]);
		i++;
	}
	pipex->paths[i] = NULL;
	pipex->path2 = find_cmd(get_command(node, n), pipex->env_path);
	ft_clean_path(pipex, pipex->path2);
}

bool	find_full_cmd(t_pipex *pipex, t_cmd *node)
{
	get_all_path(pipex, node);
	return (true);
}
