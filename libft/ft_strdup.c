/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:17:40 by hladeiro          #+#    #+#             */
/*   Updated: 2024/04/18 19:17:41 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		j;
	char	*ptr;

	j = -1;
	if (!s || !*s)
		return (ft_calloc(sizeof(char), 1));
	ptr = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (s[++j])
		ptr[j] = s[j];
	return (ptr);
}
