/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:45:53 by malourei          #+#    #+#             */
/*   Updated: 2024/12/25 23:35:15 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

static void	add_new_env(t_mini *mini, char **strs, char *strs_i)
{
	char	**tmp;

	tmp = add_env(mini->super_env, strs_i);
	if (!tmp)
	{
		free_env(strs);
		return ;
	}
	free_env(mini->super_env);
	mini->super_env = tmp;
}

static void	get_export_help(t_mini *mini, char **strs, int *i)
{
	int		index;
	char	*var;

	if (ft_strchr(strs[*i], '='))
	{
		var = ft_strdup(strs[*i]);
		if (!var)
			return ;
		ft_strrchr(var, '=');
		index = get_index(mini->super_env, var, ft_strlen(var));
		free(var);
		if (index == -1)
		{
			add_new_env(mini, strs, strs[*i]);
			i++;
			return ;
		}
		free(mini->super_env[index]);
		mini->super_env[index] = ft_strdup(strs[*i]);
		if (!mini->super_env[index])
			return ;
	}
}

void	get_export(t_mini *mini, t_node *command)
{
	int		i;

	if (!ft_strcmp(command->entry.value, ""))
	{
		print_env(mini);
		return ;
	}
	i = -1;
	while (command->entry.args[++i])
		get_export_help(mini, command->entry.args, &i);
}
