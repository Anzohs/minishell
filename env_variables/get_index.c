/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:50:56 by hladeiro          #+#    #+#             */
/*   Updated: 2024/12/14 16:30:15 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libft/libft.h"

int	get_index(char **env, char *c, size_t len)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (!ft_strncmp(env[i], c, len))
			return (i);
		i++;
	}
	return (-1);
}
