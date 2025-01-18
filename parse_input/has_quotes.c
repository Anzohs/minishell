/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:24:45 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/18 17:24:48 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	has_quotes(t_string *s)
{
	t_string	str;
	int			i;

	i = -1;
	if (!s || !*s)
		return (false);
	str = *s;
	while (str[++i] && (str[i] != '"' || str[i] != '\''))
		;
	return (false);
}
