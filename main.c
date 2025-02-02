/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:51:00 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/02 17:52:30 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_struct/mini.h"

void	init_minishell(void)
{
	mini()->prompt = "shell $ > ";
	load_signals();
	ft_lstdup(&mini()->env, &mini()->exp);
	mini()->ht = hcreate(10);
}

void	run_minishell(void)
{
	mini()->readline = readline(mini()->prompt);
	while (mini()->readline && ft_strcmp(mini()->readline, "exit"))
	{
		if (mini()->sig == 1)
		{
			mini()->sig = 0;
			free(mini()->readline);
			mini()->readline = readline(mini()->prompt);
		}
		add_history(mini()->readline);
		if (mini()->readline && *mini()->readline)
		{
			parse_input();
			transform_str();
		}
		ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
		free(mini()->readline);
		mini()->readline = readline(mini()->prompt);
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
	hdestroy(mini()->ht);
	return (mini()->exit_code);
}
