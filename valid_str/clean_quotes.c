/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:53:26 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/12 14:53:28 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static bool	have_quotes(t_string s)
{
	int	c;

	c = -1;
	if (!s || *s)
		return (true);
	while (s[++c] && s[c] != '\'' && s[c] != '"')
		;
	return (s[c] == 0);
}

void	clean_quotes(t_string *s)
{
	if (have_quotes(*s))
		take_quotes(s);
}
