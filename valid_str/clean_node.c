#include "../minishell.h"

static void	take_quotes(t_string *str)
{
	t_string	string;
	int			c;
	int			x;
	int			y;
	int			j;

	if (!str || !*str)
		return ;
	string = *str;
	c = 0;
	x = 0;
	y = 0;
	j = ft_strlen(*str);
	while (string[x])
	{
		if ((string[x] == '"' || string[x] == '\'') && !c)
			c = string[x];
		else if (string[x] == c)
			c = 0;
		else
			(*str)[y++] = string[x];
		x++;
	}
	while (y < j)
		(*str)[y++] = '\0';
}

static bool	cl(t_string s)
{
	int	c;

	c = -1;
	while (s[++c] && s[c] != '\'' && s[c] != '"')
		;
	return (s[c] == 0);
}

static void	take_spaces(t_string *s)
{
	int			j;
	t_string	str;

	str = *s;
	j = ft_strlen(str) - 1;
	while (str[j] && j > 0 && str[j] == ' ')
	{
		(*s)[j] = 0;
		--j;
	}
}

bool	clean_node(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	if (cl(n->entry.key) && cl(n->entry.value))
	{
		take_spaces((t_string *)&tmp->entry.value);
		return (true);
	}
	while (tmp)
	{
		take_quotes(&tmp->entry.key);
		if (!ft_strcmp(tmp->entry.key, "echo"))
		{
			take_quotes((t_string *)&tmp->entry.value);
			take_spaces((t_string *)&tmp->entry.value);
		}
		tmp = tmp->next;
	}
	return (true);
}
