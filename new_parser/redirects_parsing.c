/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:48:28 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/23 16:51:30 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "new_parse.h"

static int	start_redirect(t_string s)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '\'' || s[i] == '"') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if ((s[i] == '>' || s[i] == '<') && !c)
			break ;
	}
	return (i);
}

static int	end_redirect(t_string s, int start)
{
	int	i;
	int	c;

	i = start + 1;
	c = 0;
	if (s[i] == '>' || s[i] == '<')
		i++;
	while (s[i] == ' ')
		i++;
	if (s[i] == '>' || s[i] == '<' || !s[i])
		return (i);
	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		if (s[i] == ' ' && !c)
			break ;
		i++;
	}
	return (i);
}

static t_fd	*take_red(t_string *s)
{
	t_fd	*f;
	int		i;
	int		j;

	f = ft_calloc(sizeof(t_fd), 1);
	if (!f)
		return (NULL);
	i = start_redirect(*s);
	j = end_redirect(*s, i);
	f->name = ft_substr(*s, i, j - i);
	*s = new_cut(s, i, j);
	return (f);
}

static void	take_redirect(t_cmd **cmd)
{
	while (has_redirection((*cmd)->arg))
		ft_fdadd_back(&(*cmd)->fd, take_red(&(*cmd)->arg));
}

void	redirects_parsing(void)
{
	t_cmd	*cmd;

	cmd = mini()->cmd;
	while (cmd)
	{
		take_redirect(&cmd);
		cmd = cmd->next;
	}
	expantion_mark();
}
