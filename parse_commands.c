/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:26 by malourei          #+#    #+#             */
/*   Updated: 2024/11/30 18:25:58 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_search/ft_search.h"
#include "minishell.h"
#include <stdio.h>

static int	get_index(char **env, char *c, size_t len)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (!strncmp(env[i], c, len))
			return (i);
		i++;
	}
	return (-1);
}

void	update_old_pwd(t_mini *m)
{
	int		pwd_p;
	int		oldpwd_p;

	oldpwd_p = get_index(m->super_env, "OLDPWD=", 7);
	pwd_p = get_index(m->super_env, "PWD=", 4);
	if (oldpwd_p == -1 || pwd_p == -1)
		return ;
	free(m->super_env[oldpwd_p]);
	m->super_env[oldpwd_p] = NULL;
	m->super_env[oldpwd_p] = ft_strjoin("OLD", m->super_env[pwd_p]);
	printf("OLDPWD: %s\n", m->super_env[oldpwd_p]);
}

void	update_pwd(t_mini *m)
{
	int			i;
	t_string	p;

	i = get_index(m->super_env, "PWD=", 4);
	if (i < 0)
		return ;
	p = getcwd(NULL, 0);
	if (!p || p == NULL)
	{
		perror("ERROR");
		p = ft_strdup(m->super_env[i]);
		free(m->super_env[i]);
		m->super_env[i] = ft_strjoin(p, "/..");
		free(p);
		printf("PWD: %s\n", m->super_env[i]);
		return ;
	}
	free(m->super_env[i]);
	m->super_env[i] = ft_strjoin("PWD=", p);
	free(p);
	printf("PWD: %s\n", m->super_env[i]);
}

/*
Argumentos do cd

sem argumentos -> vai para o home
com o ~ -> vai para o home
com o - -> replica o oldpwd
*/

void	cd_args(t_mini *m)
{
	t_string	temp;
	int			oldpwd_i;
	int			pwd_i;

	oldpwd_i = get_index(m->super_env, "OLDPWD=", 7);
	pwd_i = get_index(m->super_env, "PWD=", 4);
	temp = ft_strdup(m->super_env[pwd_i]);
	free(m->super_env[pwd_i]);
	m->super_env[pwd_i] = ft_strdup(m->super_env[oldpwd_i]);
	free(m->super_env[oldpwd_i]);
	m->super_env[oldpwd_i] = ft_strdup(temp);
	free(temp);
	printf("%s\n", ft_strchr(m->super_env[pwd_i], '='));
}

void	parse_commands(t_mini *mini, t_node *commands)
{
	t_node	*m;

	m = commands;
	while (m)
	{
		if (!ft_strcmp(m->entry.key, "cd") && node_len(commands) == 1)
		{
			if (chdir(m->entry.value) >= 0)
			{
				update_old_pwd(mini);
				update_pwd(mini);
			}
			else if (ft_strncmp(commands->entry.value, "-", 1) == 0)
				cd_args(mini);
		}
		m = m->next;
	}
}
