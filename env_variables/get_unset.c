/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:53:15 by malourei          #+#    #+#             */
/*   Updated: 2024/12/25 22:42:52 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	array_duplicate(int *array, int array_length)
{
	int	i;
	int	j;

	i = 0;
	while ((array_length - 1) > i)
	{
		if (array[i] != -1)
		{
			j = i + 1;
			while (j < array_length)
			{
				if (array[i] == array[j])
					array[j] = -1;
				j++;
			}
		}
		i++;
	}
}

static int	*init_array(char **strs, char **envs)
{
	int		i;
	int		tam;
	int		*array;
	char	*str;

	tam = ft_count(strs);
	array = malloc(sizeof(int) * tam);
	if (!array)
	{
		free_env(strs);
		return (NULL);
	}
	i = 0;
	while (tam > i)
	{
		str = ft_strjoin(strs[i], "=");
		array[i] = get_index(envs, str, ft_strlen(str));
		i++;
		free(str);
	}
	array_duplicate(array, tam);
	return (array);
}

static void	fill_array_index(int *array, int size, char **envs, int *count)
{
	int	i;

	i = 0;
	*count = 0;
	while (i < size)
	{
		if (array[i] != -1)
		{
			envs[array[i]][0] = '\0';
			(*count)++;
		}
		i++;
	}
}

static char	**copy_new_env(t_mini *mini, int count_index)
{
	char	**new_env;
	int		i;
	int		j;

	new_env = ft_calloc(sizeof(char *), ft_count(mini->super_env) - count_index + 1);
	if (!new_env)
		return (NULL);
	i = 0;
	j = 0;
	while (mini->super_env[i] != NULL)
	{
		if (mini->super_env[i][0] != '\0')
		{
			new_env[j] = ft_strdup(mini->super_env[i]);
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}

static void	remove_env(t_mini *mini, t_node *node)
{
	int		*array;
	char	**strs;
	int		i;
	char	**new_env;

	strs = ft_split(((char *)node->entry.value), ' ');
	if (!strs)
		return ;
	array = init_array(strs, mini->super_env);
	if (!array)
		return ;
	fill_array_index(array, ft_count(strs), mini->super_env, &i);
	new_env = copy_new_env(mini, i);
	if (!new_env)
	{
		free(array);
		free_env(strs);
		return ;
	}
	free_env(mini->super_env);
	mini->super_env = new_env;
	free(array);
	free_env(strs);
}

void	get_unset(t_mini *mini, t_node *command)
{
	if (((char *)command->entry.value)[0] == '\0')
		return ;
	remove_env(mini, command);
}
