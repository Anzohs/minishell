/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:27:06 by malourei          #+#    #+#             */
/*   Updated: 2025/01/02 20:30:23 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_echo(t_mini *mini, t_node *command)
{
	int		i;
	char	*str;
	char	**strs;

	(void)mini;
	str = command->entry.value;
	strs = ft_split(str, ' ');
	if (!strs || !(*strs))
	{
		if (strs)
			free(strs);
		return ;
	}
	if (!ft_strcmp(strs[0], "-n"))
	{
		i = 1;
		while (strs[i])
		{
			if (strs[i + 1] == NULL)
				printf("%s", strs[i]);
			else
				printf("%s ", strs[i]);
			i++;
		}
		free_env(strs);
		return ;
	}
	i = 0;
	while (strs[i])
	{
		printf("%s ", strs[i]);
		i++;
	}
	printf("\n");
	free_env(strs);
}
