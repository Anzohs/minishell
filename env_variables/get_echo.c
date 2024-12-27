/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:27:06 by malourei          #+#    #+#             */
/*   Updated: 2024/12/27 22:42:46 by malourei         ###   ########.fr       */
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
	/*if (!ft_strncmp(str, "-n", 2) && ft_strlenn(str) == 2)
		return ;
	if (!ft_strncmp(str, "-n", 2) && ft_strlenn(str) > 2)
	{
		i = 2;
		while (str[i] == 32)
			i++;
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
	} */

	strs = ft_split(str, ' ');
	if (!strs)
		return ;
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
