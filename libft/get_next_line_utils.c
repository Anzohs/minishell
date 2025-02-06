/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:25:27 by malourei          #+#    #+#             */
/*   Updated: 2024/05/21 17:52:32 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strncat(char *dest, char *src, int size)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(dest);
	while (size > 0)
	{
		dest[n + i] = src[i];
		i++;
		size--;
	}
	dest[n + i] = '\0';
}
