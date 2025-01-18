/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:22:48 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/18 17:25:54 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "parsing.h"
#include <string.h>

static bool	split_need(t_string s)
{
	int	i;
	int	c;

	i = -1;
	if (!s || !*s)
		return (false);
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '"'|| s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if (s[i] == ' ' && !c)
			return (true);
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


static	void	add_matix(t_cmd **lst, t_string *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[++i]);
	(*lst)->matrix = ft_calloc(sizeof(t_string), i + 1);
	i = 0;
	j = -1;
	while (s[++i])
		(*lst)->matrix[++j] = ft_strdup(s[i]);
	(*lst)->matrix[++j] = NULL;
}

static void join_matrix(t_cmd **lst, t_string *s)
{
	t_string	*str;
	int			i;
	int			j;

	i = -1;
	j = -1;
	while ((*lst)->matrix[++i]);
	while (s[++j]);
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

static void	take_expantions(t_cmd **lst)
{
	while (is_expantion((*lst)->cmd))
		(*lst)->cmd = sub_expantion((*lst)->cmd, "ab 'ls; pwd");
	while (is_expantion((*lst)->arg))
		(*lst)->arg = sub_expantion((*lst)->arg, "Ab");
	if (split_need((*lst)->cmd))
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
		//take_quotes(&lst->cmd)
		/*
		while (lst->matix[++i])
			take_quotes(&lst->matrix[i])
		i = -1;
		*/
		lst = lst->next;
	}
}
