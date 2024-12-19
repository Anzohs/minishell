/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:53:15 by malourei          #+#    #+#             */
/*   Updated: 2024/12/19 20:52:07 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* static int	is_exist(int *array, int number)
{

} */

static	int	len_vars(char **strs)
{
	int	i;

	i = 0;
	while(strs[i] != NULL)
		i++;
	return (i);
}

static char	**copy_new_env(t_mini *mini, int *array, int tam)
{
	char	**new_env;
	int		i;
	int		j;

	(void) array;
	new_env = ft_calloc(sizeof(char *), len_vars(mini->super_env) - tam - 1);
	if (!new_env)
		return (NULL);
	i = 0;
	j = 0;
	while (mini->super_env[i] != NULL)
	{
		if (mini->super_env[i][0] == '\0')
			i++;
		else if (mini->super_env[i][0] != '\0')
		{
			new_env[j] = ft_strdup(mini->super_env[i]);
			j++;
			i++;
		}
	}
	new_env[j] = NULL;
	return (new_env);
}

static void	fill_array_index(int *array, char **envs, char **vars)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	while (envs[i] != NULL)
	{
		index = get_index(envs, vars[j], ft_strlen(vars[j]));
		if (index != -1)
		{
			envs[index][0] = '\0';
			array[j] = index;
			j++;
		}
		i++;
	}
}

static void	init_array(int *array, int len, int *count)
{
	int	i;

	i = 0;
	count = 0;
	while (len > 0)
	{
		array[i] = -1;
		count++;
		i++;
	}
}

static void	remove_env(t_mini *mini, t_node *node)
{
	int		*array;
	char	*str;
	char	**strs;
	int		i;

	str = node->entry.value;
	strs = ft_split(str, ' ');
	if (!strs)
		return ;
	array = malloc(sizeof(int) * len_vars(strs));
	if (!array)
		return ;
	init_array(array, len_vars(strs), &i);
	fill_array_index(array, mini->super_env, strs);
	strs = copy_new_env(mini, array, i);
	free(mini->super_env);
	mini->super_env = strs;
}



void	get_unset(t_mini *mini, t_node *command)
{
	//(void) mini;
	//printf("%s\n", (char *)command->entry.value);
	// ver o porquê do segfault mesmo quando não tem VAR a pesquisar
	remove_env(mini, command);
}
