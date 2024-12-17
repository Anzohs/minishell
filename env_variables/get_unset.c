/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:53:15 by malourei          #+#    #+#             */
/*   Updated: 2024/12/17 21:39:35 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	remove_env(t_mini *mini, t_node *node)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = node->entry.value;
	// tenho que percorrer a str value para ler cada argumento para usar no unset
	// e verificar se existe ou não para fazer o delete.
	while(str[i])
	{

	}
}



void	get_unset(t_mini *mini, t_node *command)
{
	(void) mini;
	printf("%s\n", (char *)command->entry.value);
}
