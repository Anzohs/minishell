/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:56:40 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/01 18:42:13 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static t_string	trim_spaces(t_string str)
{
	int	start;
	int	end;

	end = ft_strlen(str) - 1;
	start = 0;
	while (end > start && str[end] == ' ')
		str[end--] = 0;
	return (str);
}

static t_string	extract_arg(t_string s, int *i)
{
	t_string	arg;
	int			start;
	int			c;

	c = 0;
	while (s[*i] == ' ')
		(*i)++;
	start = *i;
	while (s[*i] && (s[*i] != '|' || c))
	{
		if ((s[*i] == '\'' || s[*i] == '"') && !c)
			c = s[*i];
		else if (c == s[*i])
			c = 0;
		(*i)++;
	}
	if (start == *i)
		return (ft_strdup(""));
	arg = trim_spaces(ft_substr(s, start, *i - start));
	return (arg);
}

static t_string	extract_cmd(t_string s, int *i)
{
	t_string	cmd;
	int			start;
	int			c;

	c = 0;
	while (s[*i] == ' ')
		(*i)++;
	start = *i;
	while (s[*i] && (s[*i] != ' ' || c) && (s[*i] != '|' || c))
	{
		if ((s[*i] == '\'' || s[*i] == '"') && !c)
			c = s[*i];
		else if (c == s[*i])
			c = 0;
		(*i)++;
	}
	if (start == *i)
		return (ft_strdup(""));
	cmd = ft_substr(s, start, *i - start);
	return (cmd);
}

void	copy_entry(t_entry *entry)
{
	t_cmd	*cmd;

	cmd = ft_cmdlst_new(entry->key, entry->value);
	if (!cmd)
		exit(0);
	ft_cmdlstadd_back(&mini()->cmd, cmd);
}

void	parse_input(void)
{
	int			i;
	t_string	cmd;
	t_string	arg;
	t_entry		*entry;

	i = 0;
	while (mini()->readline[i])
	{
		cmd = extract_cmd(mini()->readline, &i);
		arg = extract_arg(mini()->readline, &i);
		entry = hsearch(mini()->ht, (t_entry){cmd, arg}, ENTER);
		if (!entry)
			exit(0);
		if (mini()->readline[i] == '|')
			i++;
		copy_entry(entry);
		free(cmd);
		free(arg);
	}
}
