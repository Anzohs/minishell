/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:26 by malourei          #+#    #+#             */
/*   Updated: 2024/11/27 21:39:29 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void print_envs(char **envs)
{
	int i;

	i = 0;
	while(envs[i])
	{
		printf("M: %s\n", envs[i]);
		i++;
	}
}

int	get_env(char **envs, char *env, int j)
{
	int	i;

	i = 0;
	//print_envs(envs);
	while (envs[i])
	{
		printf("%s\n", envs[i]);
		if (ft_strncmp(envs[i], env, j) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	update_pwd(t_mini *m, char *path)
{
	int	position;

	position = get_env(m->super_env, "PWD", 3);
	printf("I: %d\n", position);
	free(m->super_env[position]);
/* 	m->super_env[position] = ft_calloc(sizeof(char), ft_strlen(path) + 6);
	if (!m->super_env[position])
		printf("malloc_failed fun: update_pwd \n");
	ft_strcpy(m->super_env[position], "PWD=");
	ft_strcat(m->super_env[position], path); */
	m->super_env[position] = ft_strjoin("PWD=", path);
	printf("%s\n", m->super_env[position]);
	if (!m->super_env[position])
		printf("malloc_failed fun: update_pwd \n");

}

void	update_old_pwd(t_mini *m)
{
	int	pwd_p;
	int	oldpwd_p;

	oldpwd_p = get_env(m->super_env, "OLDPWD=", 7);
	printf("I: %d\n", oldpwd_p);
	free(m->super_env[oldpwd_p]);
	pwd_p = get_env(m->super_env, "PWD=", 4);
	m->super_env[oldpwd_p] = ft_strjoin("OLD", m->super_env[pwd_p]);
}



void	parse_commands(t_mini *mini, t_node *commands)
{
	while (commands)
	{
		if (!ft_strcmp(commands->entry.key, "cd"))// && node_len(commands) == 1)
		{
			if (chdir(commands->entry.value) == 0)
			{
				//update_old_pwd(mini);
				update_pwd(mini, commands->entry.value);
			}
		}
		commands = commands->next;
	}
}
