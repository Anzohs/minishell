/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:29:30 by malourei          #+#    #+#             */
/*   Updated: 2024/12/25 22:42:13 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

char	**add_env(char **strs, char *env)
{
	char	**temp;
	int		i;

	temp = ft_calloc(sizeof(char *), ft_count(strs) + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		temp[i] = ft_strdup(strs[i]);
		if (!temp[i])
		{
			ft_free_strs(temp, i);
			return (NULL);
		}
		i++;
	}
	temp[i] = ft_strdup(env);
	if (!temp[i])
	{
		ft_free_strs(temp, i);
		return (NULL);
	}
	temp[i + 1] = NULL;
	return (temp);
}
