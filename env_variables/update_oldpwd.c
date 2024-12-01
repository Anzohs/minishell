
#include "../minishell.h"

void	update_oldpwd(t_mini *m)
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
}
