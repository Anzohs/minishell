/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:26 by malourei          #+#    #+#             */
/*   Updated: 2024/11/26 21:41:50 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	get_env(char **envs, char *env)
{
	int	i;

	i = 0;
	while (envs[i])
	{
		if (ft_strcmp(envs[i], env))
			return (i);
	}
	return (-1);
}

void	update_pwd(t_mini *m, char *path)
{
	int	position;

	position = get_env(m->super_env, "PWD");
	free(m->super_env[position]);
	m->super_env[position] = ft_calloc(sizeof(char), ft_strlen(path) + 6);
	if (!m->super_env[position])
		printf("malloc_failed fun: update_pwd \n");
	ft_strcpy(m->super_env[position], "PWD=");
	ft_strcat(m->super_env[position], path);
}

void	update_old_pwd(t_mini *m)
{
	int	pwd_p;
	int	oldpwd_p;

	oldpwd_p = get_env(m->super_env, "OLDPWD");
	free(m->super_env[oldpwd_p]);
	pwd_p = get_env(m->super_env, "PWD");
	m->super_env[oldpwd_p] = ft_strjoin("OLD", m->super_env[pwd_p]);
}



void	parse_commands(t_mini *mini, t_node *commands)
{
	while (commands->next)
	{
		if (ft_strcmp(commands->entry.key, "cd") && node_len(commands) == 1)
		{
			if (chdir(commands->entry.value) == 0)
			{
				update_old_pwd(mini);
				update_pwd(mini, commands->entry.value);
			}
		}
	}
}
