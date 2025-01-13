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

static bool	mark_expantion(t_string *str)
{
	int			i;
	t_string	s;
	char			c;
	bool		f;

	i = -1;
	s = *str;
	f = false;
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if (s[i] == '$' && (!c || c == '"') && s[i + 1] && ft_isalpha(s[i + 1]))
		{
			s[i] = 2;
			f = true;
		}
	}
	printf("%s\n", *str);
	return (f);
}

void	expations(t_string *comm, t_string *arg)
{
	mark_expantion(comm);
	mark_expantion(arg);
}
