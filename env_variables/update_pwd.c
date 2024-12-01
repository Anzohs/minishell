#include "../minishell.h"

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
		return ;
	}
	free(m->super_env[i]);
	m->super_env[i] = ft_strjoin("PWD=", p);
	free(p);
}
