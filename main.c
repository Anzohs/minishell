/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:51:00 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/27 23:33:35 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_struct/mini.h"
#include "new_parser/new_parse.h"

void	init_minishell(void)
{
	mini()->prompt = "shell $ > ";
	load_signals();
	ft_lstdup(&mini()->env, &mini()->exp);
}

static void	handle_sigint(void)
{
	if (mini()->sig != 0)
		mini()->sig = 0;
}

void	run_minishell(void)
{
	while (1)
	{
		handle_sigint();
		mini()->readline = readline(mini()->prompt);
		if (mini()->readline == NULL)
			break ;
		add_history(mini()->readline);
		new_parse();
		ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
		free(mini()->readline);
	}
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	(void)ac;
	stat(av[0], &mini()->stat);
	m_copy_env(env);
	init_minishell();
	run_minishell();
	ft_lstclear(&mini()->env, free);
	ft_lstclear(&mini()->exp, free);
	clear_history();
	exit(mini()->exit_code);
}
