/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:55:19 by malourei          #+#    #+#             */
/*   Updated: 2024/12/26 21:17:53 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_env(t_mini *mini, t_node *command)
{
	int	i;

	i = 0;
	while (mini->super_env[i])
	{
		printf("%s\n", mini->super_env[i]);
		i++;
	}
}
