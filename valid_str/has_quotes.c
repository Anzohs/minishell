/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:48 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/12 17:02:49 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	has_quotes(t_string s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '"')
			return (true);
	}
	return (false);
}

bool	is_expantion(t_string s)
{
	int	i;


	i = -1;
	while (s[++i])
	{
		if (s[i] == 2)
			return (true);
	}
	return (false);
}
