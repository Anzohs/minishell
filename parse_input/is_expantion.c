/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expantion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:24:59 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/18 17:25:03 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_expantion(t_string s)
{
	int	i;

	if (!s || !*s)
		return (false);
	i = -1;
	while (s[++i] && s[i] != 2)
		;
	return (s[i] == 2);
}
