/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_val_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:42:55 by malourei          #+#    #+#             */
/*   Updated: 2024/09/24 23:01:03 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = (env[i] + 5);
		i++;
	}
	return (path);
}

static char	*find_cmd(char *cmd, char **path)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	**temp3;

	i = 0;
	temp3 = ft_split(cmd, ' ');
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, temp3[0]);
		free(tmp);
		if (access(tmp2, F_OK) == 0)
		{
			clean_pointer(temp3);
			return (tmp2);
		}
		free(tmp2);
		i++;
	}
	clean_pointer(temp3);
	return (NULL);
}

static void	get_all_path(t_pipex *pipex, char **argv)
{
	int	i;
	int	j;

	i = pipex->cmd_argc;
	j = 0;
	while (i <= pipex->argc)
	{
		pipex->paths[j] = find_cmd(argv[i], pipex->env);
		ft_clean_path(pipex, pipex->paths[j]);
		j++;
		i++;
	}
	pipex->paths[j] = NULL;
	pipex->path2 = find_cmd(argv[pipex->argc + 1], pipex->env);
	ft_clean_path(pipex, pipex->path2);
}

void	find_full_cmd(t_pipex *pipex, char **env, char **argv)
{
	pipex->env = ft_split(find_path(env), ':');
	if (pipex->env == NULL)
	{
		write(2, "Error: VEIO NULO NO PATH!\n", 26);
		clean_null_env(pipex);
		exit(1);
	}
	get_all_path(pipex, argv);
	pipex->cmd2 = ft_split(argv[pipex->argc + 1], ' ');
}
