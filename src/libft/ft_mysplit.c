/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:06:06 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/12 23:06:07 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	result;

	i = 1;
	result = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		if (s[0] != c && i == 1)
			result++;
		if (s[i - 1] == c && s[i] != c)
			result++;
		i++;
	}
	return (result);
}

static int	find_del(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c || !s[i])
		return (i);
	return (0);
}

static char	**ft_free_malloc(char **ptr, int d)
{
	int	i;

	i = 0;
	while (i < d)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

char	**ft_mysplit(char const *s, char c)
{
	int		i;
	int		words;
	int		pos;
	int		d;
	char	**ptr;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr = ft_calloc((size_t)count_words((char *)s, c) + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	d = -1;
	while (++d < words)
	{
		while (s[i] == c)
			i++;
		pos = find_del((char *)s + i, c);
		ptr[d] = ft_substr(s, (unsigned int) i, (size_t)pos);
		if (!ptr[d])
			return (ft_free_malloc(ptr, d));
		i += pos + 1;
	}
	return (ptr);
}
