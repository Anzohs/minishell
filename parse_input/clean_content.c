/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:22:48 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/18 23:18:32 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static bool	split_need(t_string s)
{
	int	i;
	int	c;

	i = -1;
	if (!s || !*s || *s != 2)
		return (false);
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if (s[i] == 2 && !c)
		{
			while (ft_isalpha(s[++i]))
				;
			if (s[i] != 0 && s[i] != ' ')
				return (false);
			return (true);
		}
	}
	return (false);
}

static void	free_matrix(t_string *s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

static void	add_matix(t_cmd **lst, t_string *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[++i])
		;
	(*lst)->matrix = ft_calloc(sizeof(t_string), i + 1);
	i = 0;
	j = -1;
	while (s[++i])
		(*lst)->matrix[++j] = ft_strdup(s[i]);
	(*lst)->matrix[++j] = NULL;
}

static void	join_matrix(t_cmd **lst, t_string *s)
{
	t_string	*str;
	int			i;
	int			j;

	i = -1;
	j = -1;
	while ((*lst)->matrix[++i])
		;
	while (s[++j])
		;
	str = ft_calloc(i + j + 1, sizeof(t_string));
	str[i] = NULL;
	i = -1;
	while ((*lst)->matrix[++i])
		str[i] = ft_strdup((*lst)->matrix[i]);
	j = -1;
	while (s[++j])
		str[i++] = ft_strdup(s[j]);
	free_matrix(s);
	free_matrix((*lst)->matrix);
	(*lst)->matrix = str;
}

static void	matrix(t_cmd **lst)
{
	t_string	*s;
	int			i;

	s = split_value((*lst)->cmd);
	free((*lst)->cmd);
	(*lst)->cmd = ft_strdup(s[0]);
	add_matix(lst, s);
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s[i]);
	free(s);
	join_matrix(lst, split_value((*lst)->arg));
}

static void	take_quotes(t_string *str)
{
	t_string	s;
	int			i;
	int			y;
	int			c;

	s = *str;
	i = -1;
	y = -1;
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else
			(*str)[++y] = s[i];
	}
	while (y < i)
		(*str)[++y] = 0;
}

static t_string	get_var(t_string s)
{
	int	i;
	int	j;
	t_string	str;
	t_string	c;

	i = -1;
	while (s[++i])
	{
		if (s[i] == 2)
		{
			j = i + 1;
			while (s[j] && ft_isalpha(s[j]))
				j++;
			str = ft_substr(s + i + 1, 0, j - i -1);
			c = ft_lsthas(mini()->env,str);
			free(str);
			if (c[0] == '=')
				return (c + 1);
			return (c);
		}
	}
	return ("");
}

static void	take_expantions(t_cmd **lst)
{
	bool	f;

	f = split_need((*lst)->cmd);
	take_quotes(&(*lst)->cmd);
	take_quotes(&(*lst)->arg);
	while (is_expantion((*lst)->cmd))
		(*lst)->cmd = sub_expantion((*lst)->cmd, get_var((*lst)->cmd));
	while (is_expantion((*lst)->arg))
		(*lst)->arg = sub_expantion((*lst)->arg, get_var((*lst)->arg));
	if (f)
		matrix(lst);
	else
		(*lst)->matrix = split_value((*lst)->arg);
}

void	clean_content(void)
{
	t_cmd	*lst;

	lst = mini()->cmd;
	while (lst)
	{
		expantions(&lst->cmd);
		expantions(&lst->arg);
		take_expantions(&lst);
		lst = lst->next;
	}
}
