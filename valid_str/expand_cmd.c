#include "../minishell.h"

static bool	has_space(t_string s)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != ' ')
		;
	return (s[i] == ' ');
}

void	expand_cmd(t_string *cmd, t_string **args)
{
	t_string	new;
	t_string	*matrix;

	new = expand_args(*cmd);
	if (!has_space(new)) {
		*cmd = ft_strdup(new);
		free(new);
	}
	else
	{
		matrix = ft_mysplit(new, ' ');
		*cmd = ft_strdup(matrix[0]);
		*args = join_matrix(matrix, *args);
		printf("%s \n", **args);
	}
}
