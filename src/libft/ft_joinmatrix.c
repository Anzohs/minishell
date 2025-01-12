/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinmatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:55:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/12 21:55:35 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_matrix(char **s)
{
	int	i;

	if (!s || !*s)
		return ;
	while (s[i])
		free(s[i]);
	free(s[i]);
}

static int	matrix_len(char **s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = -1;
	while (s[++i] != NULL)
		;
	return (i);
}

char	**join_matrix(char **m1, char **m2)
{
	char	**s;
	int		i;
	int		j;

	s = ft_calloc(matrix_len(m1) + matrix_len(m2), sizeof(char *));
	i = 0;
	j = -1;
	while (m1[++i] != NULL)
		s[++j] = ft_strdup(m1[i]);
	i = -1;
	while (m2 && m2[++i])
		s[++j] = ft_strdup(m2[i]);
	free_matrix(m1);
	if (m2)
		free_matrix(m2);
	s[j] = NULL;
	return (s);
}
