/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:15:58 by malourei          #+#    #+#             */
/*   Updated: 2025/02/06 21:15:58 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"

int	is_arrow(char *str, int index)
{
	if (!ft_strcmp(str, ">") || !ft_strcmp(str, ">>") || !ft_strcmp(str, "<")
		|| !ft_strcmp(str, "<<"))
		return (index);
	return (-1);
}

char	**new_args(char **strs, int index)
{
	int		i;
	char	**new_strs;

	i = 0;
	new_strs = ft_calloc(index + 1, sizeof(char *));
	if (!new_strs)
	{
		write(2, "Deu merda\n", 10);
		return (NULL);
	}
	while (i < index)
	{
		printf("ARG1[%d]: %s\n", i, strs[i]);
		new_strs[i] = ft_strdup(strs[i]);
		if (!new_strs[i])
		{
			write(2, "Deu merda2\n", 11);
			return (NULL);
		}
		i++;
	}
	new_strs[i] = NULL;
	return (new_strs);
}

char	**new_arrows(char **strs, int index)
{
	int		i;
	int		j;
	int		size;
	char	**new_strs;

	i = 0;
	size = 0;
	j = index;
	while (strs[j] != NULL)
	{
		size++;
		j++;
	}
	new_strs = ft_calloc(size + 1, sizeof(char *));
	if (!new_strs)
	{
		write(2, "Deu merda\n", 10);
		return (NULL);
	}
	while (i < size)
	{
		new_strs[i] = ft_strdup(strs[index]);
		if (!new_strs[i])
		{
			write(2, "Deu merda2\n", 11);
			return (NULL);
		}
		i++;
		index++;
	}
	new_strs[i] = NULL;
	return (new_strs);
}

void	create_arrow(t_cmd *node)
{
	char	**arrow;
	char	**new_arg;
	int		i;

	i = 0;
	if (node->matrix[0] == NULL)
		return ;
	while (node->matrix[i] != NULL)
	{
		if (is_arrow(node->matrix[i], i) >= 0)
		{
			new_arg = new_args(node->matrix, i);
			arrow = new_arrows(node->matrix, i);
			break ;
		}
		i++;
	}
	if (node->matrix[i] == NULL)
		return ;
	free_matrix(node->matrix);
	node->matrix = new_arg;
	node->arrow = arrow;
}
