/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:56:46 by malourei          #+#    #+#             */
/*   Updated: 2024/11/25 21:57:23 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *c, char *d)
{
	int	i;

	i = 0;
	while (c[i] == d[i] && d[i])
		i++;
	if (d[i] == c[i])
		return (0);
	return (1);
}
