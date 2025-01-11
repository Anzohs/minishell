#include "../minishell.h"

static bool	is_home(t_string s)
{
	return (!s || !ft_strcmp(s, "") || !ft_strcmp(s, "~"));
}

static void	cd_home(void)
{
	int			home[4];
	t_string	tmp;
	t_string	pwd_temp;
	char		**strs;

	*home = get_index(mini()->super_env, "HOME=", 5);
	if (*home == -1)
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

void	cd_builtin(void)
{
	if (is_home(mini()->commands->entry.key))
		cd_home();
}
