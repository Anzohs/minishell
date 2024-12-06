
#include "../minishell.h"

int	get_index(char **env, char *c, size_t len)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (!ft_strncmp(env[i], c, len))
			return (i);
		i++;
	}
	return (-1);
}
