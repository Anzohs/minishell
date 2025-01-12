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

	(void)mini;
	if (!ft_strcmp(command->entry.args[0], "-n"))
	{
		i = 1;
		while (command->entry.args[0][i])
		{
			if (command->entry.args[i + 1] == NULL)
				printf("%s", command->entry.args[i]);
			else
				printf("%s ", command->entry.args[i]);
			i++;
		}
		return ;
	}
	i = -1;
	while (command->entry.args[++i])
		printf("%s ", command->entry.args[i]);
	printf("\n");
}
