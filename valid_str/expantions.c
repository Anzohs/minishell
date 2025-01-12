/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:53:40 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/12 14:53:41 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	is_expantion(t_string *str)
{
	int			i;
	t_string	s;
	bool		s_quotes;
	bool		d_quotes;
	bool		f;

	i = -1;
	s = *str;
	d_quotes = false;
	s_quotes = false;
	f = false;
	while (s[++i])
	{
		if (s[i] == '\'' && !d_quotes)
			s_quotes = !s_quotes;
		else if (s[i] == '"' && !s_quotes)
			d_quotes = !d_quotes;
		else if (s[i] == '$' && !s_quotes && s[i + 1] && ft_isalpha(s[i + 1]))
		{
			s[i] = 2;
			f = true;
		}
	}
	return (f);
}

void	expations(t_string *comm, t_string *arg)
{
	is_expantion(comm);
	is_expantion(arg);
}
