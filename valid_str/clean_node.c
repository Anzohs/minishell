#include "../minishell.h"
#include "valid_str.h"
#include <stdbool.h>
#include <stdio.h>

/*
static bool	is_letter(int c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	if (c >= 'A' && c <= 'Z')
		return (true);
	return (false);
}

static void	take_quotes(t_string *str)
{
	t_string	string;
	int			c;
	int			x;

	if (!str || !*str)
		return ;
	c = 0;
	x = -1;
	string = *str;
	while (string[++x])
	{
		if ((string[x] == '"' || string[x] == '\'') && !c)
		{
			c = string[x];
			string[x] = 3;
		}
		else if (string[x] == c)
			c = 0;
		else if ((c == 0 || c == '"') && (string[x] == '$' && \
			is_letter(string[x + 1])))
			string[x + 1] = 4;
	}
	printf("%s \n", *str);
}

bool	not_clean(t_string s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == 3 || s[i] == 2)
			return (false);
	}
	return (true);
}

static int	special_len(t_string s)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != 3)
			j++;
	}
	return (j);
}

static void	new_value(t_string value)
{
	t_string	new;
	int			i;
	int			j;

	i = -1;
	j = -1;
	new = ft_calloc(sizeof(value), special_len(value) + 1);
	while (value[i++])
	{
		if (value[i] != 2)
			new[++j] = value[i];
	}
	if (value)
		free(value);
	value = new;
}


static void	new_key(t_string key, void *value)
{
	t_string	new;
	int			i;
	int			j;

	i = -1;
	j = -1;
	new = ft_calloc(sizeof(key), special_len(key) + 1);
	while (key[i++])
	{
		if (key[i] != 2)
			new[++j] = key[i];
	}
	free(key);
	key = new;
	printf("new_key : %s \n", key);
	if (not_clean(value))
		new_value(value);
}

static bool	new_node(t_node **n)
{
	t_node	*tmp;

	tmp = *n;
	while (tmp)
	{
		if (not_clean(tmp->entry.key))
			new_key(tmp->entry.key, tmp->entry.value);
		printf("%s \n", tmp->entry.key);
		if (not_clean(tmp->entry.value))
			new_value(tmp->entry.value);
		tmp = tmp->next;
	}
	return (true);
}
*/

static void	take_quotes(t_string *str)
{
	t_string	string;
	int			c;
	int			x;
	int			y;

	if (!str || !*str)
		return ;
	string = *str;
	c = 0;
	x = 0;
	y = 0;
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
	(*str)[y] = '\0';
}

static bool	cl(t_string s)
{
	int	c;

	c = -1;
	while (s[++c] && s[c] != '\'' && s[c] != '"')
		;
	return (s[c] == 0);
}

bool	clean_node(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	if (cl(n->entry.key))
		return (true);
	while (tmp)
	{
		take_quotes(&tmp->entry.key);
		if (!ft_strcmp(tmp->entry.key, "echo"))
			take_quotes((t_string *)&tmp->entry.value);
		tmp = tmp->next;
	}
	return (true);
}
