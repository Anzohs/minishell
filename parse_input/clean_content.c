/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:22:48 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/09 17:24:32 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

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


static void take_spaces(t_string *s)
{
	int	i;

	i = ft_strlen(*s) - 1;
	if (i == -1)
		return;
	while (i &&  (*s)[i] == ' ')
		(*s)[i--] = 0;
}

static void	take_expantions(t_cmd **lst)
{
	bool	f;
	int		i;

	i = -1;
	f = split_need((*lst)->cmd);
	take_quotes(&(*lst)->cmd);
	while (is_expantion((*lst)->cmd))
		(*lst)->cmd = sub_expantion((*lst)->cmd, get_var((*lst)->cmd));
	while (is_expantion((*lst)->arg))
		(*lst)->arg = sub_expantion((*lst)->arg, get_var((*lst)->arg));
	if (f && *(*lst)->cmd)
		matrix(lst);
	else
		(*lst)->matrix = split_value((*lst)->arg);
	while ((*lst)->matrix && (*lst)->matrix[++i] != NULL)
	{
		take_quotes(&(*lst)->matrix[i]);
		take_spaces(&(*lst)->matrix[i]);
	}
}

void	clean_content(void)
{
	t_cmd	*lst;

	lst = mini()->cmd;
	while (lst)
	{
		if (has_redirection(lst->cmd) || has_redirection(lst->arg))
			parse_redirects(&lst);
		expantions(&lst->cmd);
		expantions(&lst->arg);
		take_expantions(&lst);
		lst = lst->next;
	}
}
