/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:58 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/12 17:02:59 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	expantion_start(t_string cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == 2)
			return (i);
	}
	return (i);
}

static int	count_expantions(t_string cmd)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (cmd[++i])
	{
		if (cmd[i] == 2)
			j++;
	}
	return (j);
}

t_string	change_value(t_string s, t_string cmd, t_string n)
{
	t_string	new;
	int			i;
	int			k;
	int			u;

	i = 0;
	k = 0;
	u = 0;
	if (n)
		free(n);
	new = ft_calloc(ft_strlen(s) + ft_strlen(cmd) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (cmd[k])
	{
		if (cmd[k] == 2)
		{
			k++;
			while (s[u])
				new[i++] = s[u++];
			while (cmd[k] && cmd[k] != ' ' && cmd[k] != '"' && cmd[k] != 2)
				k++;
		}
		else
			new[i++] = cmd[k++];
	}
	return (new);
}

t_string	expand_args(t_string cmd)
{
	t_string	new;
	int			j;
	int			i;

	j = count_expantions(cmd);
	new = NULL;
	if (!j)
		return (cmd);
	i = -1;
	while (++i < j)
	{
		new = change_value(get_envvars(cmd), cmd, new);
		free(cmd);
		cmd = ft_strdup(new);
	}
	return (cmd);
}
