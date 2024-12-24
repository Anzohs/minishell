/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:45:53 by malourei          #+#    #+#             */
/*   Updated: 2024/12/24 18:36:01 by malourei         ###   ########.fr       */
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
	char	**strs;
	int		i;

	if (!ft_strcmp(command->entry.value, ""))
		print_env(mini);
	strs = ft_split((char *)command->entry.value, ' ');
	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		if (ft_strchr(strs[i], '='))
		{
			var = ft_strdup(strs[i]);
			if (!var)
			{
				free_env(strs);
				return ;
			}
			ft_strrchr(var, '=');
			index = get_index(mini->super_env, var, ft_strlen(var));
			if (index == -1)
			{
				tmp = add_env(mini->super_env, strs[i]);
				free_env(mini->super_env);
				mini->super_env = tmp;
				free(var);
				continue ;
			}
			free(var);
			free(mini->super_env[index]);
			mini->super_env[index] = ft_strdup(strs[i]);
			if (!mini->super_env[index])
				return ;
		}
		i++;
	}
	free_env(strs);
}
