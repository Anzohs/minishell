#include "../minishell.h"

static int	find_space(t_string s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == 2 || s[i] == '"' || s[i] == '\'')
			return (i);
	}
	return (i);
}
t_string	get_envvars(t_string s)
{
	t_string	var;
	int			i;
	int			j;

	var = ft_strchr(s, 2);
	if (!var)
		return (NULL);
	j = find_space(var);
	var = ft_substr(var, 0, j);
	i = get_index(mini()->super_env, var, ft_strlen(var));
	if (i == -1)
		var = "";
	else
		var = ft_strchr(mini()->super_env[i], '=');
	return (var);
}
