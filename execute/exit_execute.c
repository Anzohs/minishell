/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:18:47 by malourei          #+#    #+#             */
/*   Updated: 2025/02/28 00:33:44 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	exit_minishell(void)
{
	//clean_all(pipex);
	ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
	free(mini()->readline);
	ft_lstclear(&mini()->env, free);
	ft_lstclear(&mini()->exp, free);
	clear_history();
	exit(mini()->exit_code);
}
