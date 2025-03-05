/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:18:47 by malourei          #+#    #+#             */
/*   Updated: 2025/03/05 01:02:22 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include <unistd.h>

static void	clean_pipes(void)
{
	if (mini()->pipes == -1)
		ft_close_all_p(mini()->pipex);
	else if (mini()->pipes == 0)
		ft_close_all_1(mini()->pipex);
	else
		ft_close_all_m(mini()->pipex, mini()->pipes);
	ft_close_all_files(mini()->cmd);
	clean_all(mini()->pipex);
	ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
	free(mini()->readline);
	ft_lstclear(&mini()->env, free);
	ft_lstclear(&mini()->exp, free);
	clear_history();
	exit(mini()->exit_code);
}

void	exit_minishell(void)
{
	if (mini()->pipex)
		clean_pipes();
	ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
	free(mini()->readline);
	ft_lstclear(&mini()->env, free);
	ft_lstclear(&mini()->exp, free);
	clear_history();
	ft_putstr_fd("exit", STDOUT_FILENO);
	exit(mini()->exit_code);
}
