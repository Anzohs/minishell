/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:07:04 by malourei          #+#    #+#             */
/*   Updated: 2024/11/28 20:52:47 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_envs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

void	copy_env(t_mini *mini, char **env)
{
	int	i;

	i = 0;
	mini->super_env = ft_calloc(sizeof(char *), (count_envs(env) + 1));
	if (!mini->super_env)
	{
		free(mini->super_env);
		exit (1);
	}
	while (env[i])
	{
		mini->super_env[i] = ft_strdup(env[i]);
		if (!mini->super_env[i])
		{
			ft_free_strs(mini->super_env, i);
			exit (1);
		}
		i++;
	}
	mini->super_env[i] = NULL;
}
