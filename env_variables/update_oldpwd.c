
#include "../minishell.h"

//Zé Função repedita
static int	ft_count(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

//Zé Função repedita
static char	**add_env(char **strs, char *env)
{
	char	**temp;
	int		i;

	temp = ft_calloc(sizeof(char *), ft_count(strs) + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		temp[i] = ft_strdup(strs[i]);
		if (!temp[i])
		{
			ft_free_strs(temp, i);
			return (NULL);
		}
		i++;
	}
	temp[i] = ft_strdup(env);
	if (!temp[i])
	{
		ft_free_strs(temp, i);
		return (NULL);
	}
	temp[i + 1] = NULL;
	return (temp);
}

static void	create_oldpwd(t_mini *mini)
{
	int		pwd_p;
	char	*new_old_pwd;
	char	**envs;

	pwd_p = get_index(mini->super_env, "PWD=", 4);
	new_old_pwd = ft_strjoin("OLD", mini->super_env[pwd_p]);
	if (!new_old_pwd)
		return ;
	envs = add_env(mini->super_env, new_old_pwd);
	free_env(mini->super_env);
	free(new_old_pwd);
	mini->super_env = envs;
}

void	update_oldpwd(t_mini *m)
{
	int		pwd_p;
	int		oldpwd_p;

	oldpwd_p = get_index(m->super_env, "OLDPWD=", 7);
	if (oldpwd_p == -1)
		create_oldpwd(m);
	pwd_p = get_index(m->super_env, "PWD=", 4);
	if (oldpwd_p == -1 || pwd_p == -1)
		return ;
	free(m->super_env[oldpwd_p]);
	m->super_env[oldpwd_p] = NULL;
	m->super_env[oldpwd_p] = ft_strjoin("OLD", m->super_env[pwd_p]);
}
