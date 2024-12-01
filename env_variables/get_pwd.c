
# include "../minishell.h"

void	get_pwd(t_string s, int i)
{
	printf("%s \n", s + i);
	free(s);
}
