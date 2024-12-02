#ifndef ENVVARIABLES_H
# define ENVVARIABLES_H

# include <unistd.h>
typedef char	*t_string;
typedef struct s_minishell	t_mini;

void	update_oldpwd(t_mini *m);
int		get_index(char **env, char *c, size_t len);
void	update_pwd(t_mini *m);
void	get_pwd(t_string s, int i);

#endif
