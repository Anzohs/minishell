/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:26 by malourei          #+#    #+#             */
/*   Updated: 2025/01/10 18:41:33 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "src/libft/libft.h"
#include "valid_str/valid_str.h"

void	cd_args(t_mini *m)
{
	t_string	temp;
	int			dir;
	int			oldpwd_i;
	int			pwd_i;
	t_string	old_tmp;

	oldpwd_i = get_index(m->super_env, "OLDPWD=", 7);
	if (oldpwd_i == -1)
	{
		write(2, "OLDPWD: not defined\n", 20);
		return ;
	}
	pwd_i = get_index(m->super_env, "PWD=", 4);
	temp = ft_strdup(m->super_env[pwd_i]);
	old_tmp = ft_strdup(m->super_env[oldpwd_i]);
	free(m->super_env[pwd_i]);
	free(m->super_env[oldpwd_i]);
	m->super_env[pwd_i] = ft_strdup(old_tmp + 3);
	m->super_env[oldpwd_i] = ft_strjoin("OLD", temp);
	free(temp);
	free(old_tmp);
	dir = chdir(ft_strchr(m->super_env[pwd_i], '='));
	if (dir == -1)
		perror("CD -");
}

void	cd_home(t_mini *m)
{
	int			home;
	int			old_pwd;
	int			pwd;
	int			dir;
	t_string	tmp;
	t_string	pwd_temp;
	char		**strs;

	home = get_index(m->super_env, "HOME=", 5);
	if (home == -1)
	{
		write(2, "cd: HOME not set\n", 17);
		return ;
	}
	pwd = get_index(m->super_env, "PWD=", 4);
	old_pwd = get_index(m->super_env, "OLDPWD=", 7);
	if (old_pwd == -1)
	{
		strs = add_env(m->super_env, "OLDPWD=");
		free_env(m->super_env);
		m->super_env = strs;
		old_pwd = get_index(m->super_env, "OLDPWD=", 7);
	}
	free(m->super_env[old_pwd]);
	pwd_temp = ft_strdup(m->super_env[pwd]);
	m->super_env[old_pwd] = ft_strjoin("OLD", pwd_temp);
	free(pwd_temp);
	free(m->super_env[pwd]);
	tmp = ft_strdup(m->super_env[home]);
	m->super_env[pwd] = ft_strjoin("PWD=", tmp + 5);
	free(tmp);
	dir = chdir(ft_strchr(m->super_env[pwd], '='));
	if (dir == -1)
		perror("CD ~");
}

void	parse_commands(t_mini *mini, t_node *commands)
{
	t_node	*m;

	m = commands;
	if (node_len(m) < 1 || !clean_command(mini) || !clean_node(commands))
		return ;
	if (is_biltin(commands) && node_len(commands) == 1)
	{
		if (!ft_strcmp(m->entry.key, "cd"))
			cd_biltin();
		if (!ft_strcmp(m->entry.key, "pwd"))
			get_pwd(getcwd(NULL, 0), 0);
		if (!ft_strcmp(m->entry.key, "export"))
			get_export(mini, m);
		if (!ft_strcmp(m->entry.key, "unset"))
			get_unset(mini, m);
		if (!ft_strcmp(m->entry.key, "env"))
			get_env(mini, m);
		if (!ft_strcmp(m->entry.key, "echo"))
			get_echo(mini, m);
	}
	else
		pipex(mini, m);
}
