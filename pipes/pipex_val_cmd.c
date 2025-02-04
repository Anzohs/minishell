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

#include "../mini_struct/mini.h"

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
	return (ft_strdup(cmd));
}

static t_string	get_command(t_cmd *n, int i)
{
	t_cmd	*tmp;
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
	return (tmp->cmd);
}

static void	get_all_path(t_pipex *pipex, t_cmd *node)
{
	int	i;
	int	n;

	i = 0;
	n = node_len(node) - 1;
	while (i < n)
	{
		pipex->paths[i] = find_cmd(get_command(node, i), pipex->env);
		//if (!pipex->paths[i])
			//pipex->val_cmd++;
		ft_clean_path(pipex, pipex->paths[i]);
		i++;
	}
	pipex->paths[i] = NULL;
	pipex->path2 = find_cmd(get_command(node, n), pipex->env);
	//if (!pipex->path2)
		//return ;
	ft_clean_path(pipex, pipex->path2);
}

bool	find_full_cmd(t_pipex *pipex, t_mini *mini, t_cmd *node)
{
	// Confirmar o pipex.env[0] Se não tem o PATH= no inicio
/* 	char	*tmp;

	tmp = ft_strdup(pipex->env[0] + 5);
	free(pipex->env[0]);
	pipex->env[0] = ft_strdup(tmp);
	free(tmp); */
	get_all_path(pipex, node);
	return (true);
	//pipex->cmd2 = (char **)get_command(node, node_len(node) - 1);
}

/*
Tenho que estudar uma forma de saber os comandos validos...
tenho que fazer o pipe e por fim imprimir os cmd invalidos (COMMAND NOT FOUNT)
*/
