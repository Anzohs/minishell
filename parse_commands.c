/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:26 by malourei          #+#    #+#             */
/*   Updated: 2024/11/28 21:36:41 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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

/* void	update_old_pwd(t_mini *m)
{
	int	pwd_p;
    int	oldpwd_p;
    char *s;

    oldpwd_p = get_env(m->super_env, "OLDPWD=", 7);
    pwd_p = get_env(m->super_env, "PWD=", 4);

    if (oldpwd_p == -1 || pwd_p == -1)
        return;

    free(m->super_env[oldpwd_p]);
	m->super_env[oldpwd_p] = NULL;
    s = ft_strjoin("OLD", m->super_env[pwd_p]);
    m->super_env[oldpwd_p] = ft_strdup(s);
    free(s);

    printf("OLDPWD: %s\n", m->super_env[oldpwd_p]);
} */

void	update_pwd(t_mini *m)
{
	int	i = get_index(m->super_env, "PWD=", 4);
	if (i < 0)
		return;
	free(m->super_env[i]);
	t_string p = getcwd(NULL, 0);
	t_string cwd = ft_strjoin("PWD=", p);
	free(p);
    m->super_env[i] = ft_strdup(cwd);
    free(cwd);
	printf("%s\n",m->super_env[i]);
}

void	parse_commands(t_mini *mini, t_node *commands)
{
	t_node *m = commands;
	//printf("MACHO \n");
	while (m)
	{
		if (!ft_strcmp(m->entry.key, "cd"))// && node_len(commands) == 1)
		{
			if (chdir(m->entry.value) == 0)
			{
				//update_old_pwd(mini);
				update_pwd(mini);
			}
		}
		m = m->next;
	}
}
