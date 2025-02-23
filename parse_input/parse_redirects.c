/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:54:20 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/23 21:27:40 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

bool	has_redirection(t_string s)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if (!c && (s[i] == '<' || s[i] == '>'))
			return (true);
		i++;
	}
	return (false);
}

