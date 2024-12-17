/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:45:53 by malourei          #+#    #+#             */
/*   Updated: 2024/12/17 20:10:46 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


static int	ft_count(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

static char	**add_env(char **strs, char *env)
{
	char	**temp;
	int		i;

	temp = ft_calloc(sizeof(char *), ft_count(strs) + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		temp[i] = ft_strdup(strs[i]);
		if (!temp[i])
		{
			ft_free_strs(temp, i);
			return (NULL);
		}
		i++;
	}
	temp[i] = ft_strdup(env);
	if (!temp[i])
	{
		ft_free_strs(temp, i);
		return (NULL);
	}
	temp[i + 1] = NULL;
	return (temp);
}

static void	print_env(t_mini *m)
{
	int	i;

	i = 0;
	while (m->super_env[i])
	{
		printf("declare -x %s\n", m->super_env[i]);
		i++;
	}
}

void	get_export(t_mini *mini, t_node *command)
{
	int		index;
	char	*var;
	char	**tmp;

	if (!ft_strcmp(command->entry.value, ""))
		print_env(mini);
	if (!ft_strchr(command->entry.value, '='))
		return ;
	else
	{
		var = ft_strdup(command->entry.value);
		if (!var)
			return ;
		ft_strrchr(var, '=');
		index = get_index(mini->super_env, var, ft_strlen(var));
		if (index == -1)
		{
			tmp = add_env(mini->super_env, command->entry.value);
			free_env(mini->super_env);
			mini->super_env = tmp;
			free(var);
			return ;
		}
		free(var);
		free(mini->super_env[index]);
		var = ft_strdup(command->entry.value);
		if (!var)
			return;
		mini->super_env[index] = ft_strdup(var);
		free(var);
	}
}
