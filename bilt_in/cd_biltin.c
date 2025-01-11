#include "../minishell.h"
#include <stdio.h>

static bool	is_home(t_string s)
{
	return (!s || !*s || !ft_strcmp(s, "") || !ft_strcmp(s, "~"));
}

static void	cd_args(void)
{
	t_string	temp;
	int			dir;
	int			oldpwd_i;
	int			pwd_i;
	t_string	old_tmp;

	oldpwd_i = get_index(mini()->super_env, "OLDPWD=", 7);
	if (oldpwd_i == -1)
	{
		write(2, "OLDPWD: not defined\n", 20);
		return ;
	}
	pwd_i = get_index(mini()->super_env, "PWD=", 4);
	temp = ft_strdup(mini()->super_env[pwd_i]);
	old_tmp = ft_strdup(mini()->super_env[oldpwd_i]);
	free(mini()->super_env[pwd_i]);
	free(mini()->super_env[oldpwd_i]);
	mini()->super_env[pwd_i] = ft_strdup(old_tmp + 3);
	mini()->super_env[oldpwd_i] = ft_strjoin("OLD", temp);
	free(temp);
	free(old_tmp);
	dir = chdir(ft_strchr(mini()->super_env[pwd_i], '='));
	if (dir == -1)
		perror("CD -");
}


static void	cd_home(void)
{
	int			home[4];
	t_string	tmp;
	t_string	pwd_temp;
	char		**strs;

	home[0] = get_index(mini()->super_env, "HOME=", 5);
	if (home[0] == -1)
	{
		write(2, "cd: HOME not set\n", 17);
		return ;
	}
	home[1] = get_index(mini()->super_env, "PWD=", 4);
	home[2] = get_index(mini()->super_env, "OLDPWD=", 7);
	if (home[2] == -1)
	{
		strs = add_env(mini()->super_env, "OLDPWD=");
		free_env(mini()->super_env);
		mini()->super_env = strs;
		home[2] = get_index(mini()->super_env, "OLDPWD=", 7);
	}
	free(mini()->super_env[home[2]]);
	pwd_temp = ft_strdup(mini()->super_env[home[1]]);
	mini()->super_env[home[2]] = ft_strjoin("OLD", pwd_temp);
	free(pwd_temp);
	free(mini()->super_env[home[1]]);
	tmp = ft_strdup(mini()->super_env[home[0]]);
	mini()->super_env[home[1]] = ft_strjoin("PWD=", tmp + 5);
	free(tmp);
	home[3] = chdir(ft_strchr(mini()->super_env[home[1]], '='));
	if (home[3] == -1)
		perror("CD ~");
}

static void	update_env(void)
{
	update_oldpwd(mini());
	update_pwd(mini());
}

void	cd_biltin(void)
{
	if (is_home(mini()->commands->entry.value))
		(cd_home());
	else if (!ft_strcmp(mini()->commands->entry.value, "-"))
		(cd_args());
	else if (chdir(mini()->commands->entry.value) >= 0)
		(update_env());
	else if (chdir(mini()->commands->entry.value) < 0)
	{
		perror((t_string)mini()->commands->entry.value);
		return;
	}
	get_pwd(getcwd(NULL, 0), 0);
}
