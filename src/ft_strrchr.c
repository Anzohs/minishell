/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:07:41 by malourei          #+#    #+#             */
/*   Updated: 2024/11/18 00:41:12 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrchr(char *s, char c)
{
	size_t	tamanho;

	tamanho = ft_strlen(s);
	while (s[tamanho] != c)
	{
		if (tamanho == 0)
			return (NULL);
		tamanho--;
	}
	s[tamanho] = '\0';
	return (s);
}
