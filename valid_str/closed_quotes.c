/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:47:03 by hladeiro          #+#    #+#             */
/*   Updated: 2024/12/22 15:53:20 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	closed_quotes(t_string str)
{
	int		i;
	char	c;

	i = -1;
	c = 0;
	while (str[++i])
	{
		if ((str[i] == '"' || str[i] == '\'') && !c)
			c = str[i];
		else if (str[i] == c)
			c = 0;
	}
	return (c == 0);
}
