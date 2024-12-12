/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:45:53 by malourei          #+#    #+#             */
/*   Updated: 2024/12/12 20:29:13 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_export(t_node *command)
{
	if (!ft_strrchr(command->entry.value, '='))
	{
		printf("MACHO\n");
		return ;
	}

}
