#include "../minishell.h"
#include "valid_str.h"
#include <ctype.h>
#include <stdbool.h>

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

static bool	is_expantion(t_string s)
{
	int		i;
	bool	s_quotes;
	bool	d_quotes;

	i = -1;
	d_quotes = false;
	s_quotes = false;
	while (s[++i])
	{
		if (s[i] == '\'' && !d_quotes)
			s_quotes = !s_quotes;
		else if (s[i] == '"' && !s_quotes)
			d_quotes = !d_quotes;
		else if (s[i] == '$' && !s_quotes)
		{
			if (s[i + 1] && (isalnum(s[i + 1])))
			{
				s[i] = 2;
				return (true);
			}
		}
	}
	return (false);
}

static void	expantion(t_string *comm, t_string *arg)
{
	if (is_expantion(*comm) || is_expantion(*arg))
	{
		printf("expantion \n %s", *arg);
		printf("Expantion alert! \n");
		exit(0);
	}
}

bool	clean_node(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	if (cl(n->entry.key) && cl(n->entry.value))
	{
		expantion(&n->entry.key, (t_string *)&n->entry.value);
		take_spaces((t_string *)&tmp->entry.value);
		return (true);
	}
	while (tmp)
	{
		take_quotes(&tmp->entry.key);
		take_quotes(&tmp->entry.key);
		take_spaces((t_string *)&tmp->entry.value);
		take_quotes((t_string *)&tmp->entry.value);
		tmp = tmp->next;
	}
	return (true);
}
