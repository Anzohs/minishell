#include "../minishell.h"

static bool	has_space(t_string s)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != ' ')
		;
	return (s[i] == ' ');
}


void	expand_cmd(t_string cmd, t_string *args)
{
	t_string	new;
	t_string	*matrix;

	new = expand_args(cmd);
	if (!has_space(new))
		cmd = new;
	else
	{
		matrix = ft_split(new, ' ');
		cmd = ft_strdup(matrix[0]);
		args = join_matrix(matrix, args);
	}
}
