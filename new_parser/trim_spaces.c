/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:01:56 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/23 18:01:57 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_parse.h"

void	trim_spaces(t_string *s)
{
	int	i;

	i = ft_strlen(*s) - 1;
	if (i == -1)
		return ;
	while (i && (*s)[i] == ' ')
		(*s)[i] = 0;
}

void	trim_front_spaces(t_string *s)
{
	int			i;
	t_string	str;

	i = -1;
	while ((*s)[++i] == ' ')
		;
	str = ft_substr(*s, i, ft_strlen(*s) - i);
	free(*s);
	*s = str;
}
