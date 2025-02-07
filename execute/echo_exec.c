
#include "../mini_struct/mini.h"

static void	echo_new_line(t_string *matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
	{
		ft_putstr_fd(matrix[i], 1);
		if (matrix[i+1])
			ft_putchar_fd(' ', 1);
	}
	ft_putendl_fd("", 1);
}

static void	echo_no_line(t_string *matrix)
{
	int	i;

	i = 0;
	while (matrix[++i])
	{
		ft_putstr_fd(matrix[i], 1);
		if (matrix[i+1])
			ft_putchar_fd(' ', 1);
	}
}

static bool	new_line(t_string s)
{
	int	i;

	i = 0;
	if (!s || !*s || *s != '-' || s[1] != 'n')
		return (true);
	while (s[++i] == 'n')
		;
	return (!(s[i] == 0));
}

void	echo_exec(t_cmd *cmd)
{
	if (new_line(cmd->matrix[0]))
		return (echo_new_line(cmd->matrix));
	return (echo_no_line(cmd->matrix));
}
