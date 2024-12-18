/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:53:15 by malourei          #+#    #+#             */
/*   Updated: 2024/12/18 00:07:49 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_envs(t_mini *mini, int index)
{
	free(mini->super_env[index]);

}


static void	remove_env(t_mini *mini, t_node *node)
{
	int		i;
	int		j;
	int		index;
	char	*str;
	char	**strs;

	str = node->entry.value;
	// tenho que percorrer a str value para ler cada argumento para usar no unset
	// e verificar se existe ou não para fazer o delete.
	strs = ft_split(str, ' ');
	i = 0;
	while (strs[i] != NULL)
	{
		index = get_index(mini->super_env, strs[i], ft_strlen(strs[i]));
		if (index == -1)
		{
			i++;
			continue ;
		}

	}
}



void	get_unset(t_mini *mini, t_node *command)
{
	(void) mini;
	printf("%s\n", (char *)command->entry.value);
}
