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

int	find_space(t_string s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ')
			return (i);
	}
	return (i);
}

t_string	copy_envvars(t_string s)
{
	t_string	var;
	int			i;
	int			j;

	var = ft_strchr(s, 2);
	if (!var)
		return (NULL);
	j = find_space(var + i);
	var = ft_substr(var, 0, j);
	i = get_index(mini()->super_env, var, ft_strlen(var));
	if (i == -1)
		var = NULL;
	else
		var = ft_strchr(mini()->super_env[i], '=');
}

t_string	expand_args(t_string cmd)
{
	int	j;
	int	i;

	j = count_expantions(cmd);
	if (!j)
		return (cmd);
	i = -1;
	while (++i < j)
		copy_envvars(cmd);
}
