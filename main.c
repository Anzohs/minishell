/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:51:00 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/14 22:51:01 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_struct/mini.h"

void	init_minishell(void)
{
	mini()->prompt = "shell $ > ";
	ft_lstdup(&mini()->env, &mini()->exp);
	mini()->ht = hcreate(10);
	mini()->readline = readline(mini()->prompt);
}


void	run_minishell(void)
{
	while (mini()->readline && ft_strcmp(mini()->readline, "exit"))
	{
		parse_input();
		add_history(mini()->readline);
		free(mini()->readline);
		mini()->readline = readline(mini()->prompt);
		write(1, "aqui\n", 1);
	}
}

int	main(int ac, char **av, char **env)
{
	//mini()->readline = readline("shell");
	(void)av;
	(void)ac;
	m_copy_env(env);
	init_minishell();
	run_minishell();
	ft_lstclear(&mini()->env, free);
	ft_lstclear(&mini()->exp, free);
	return (0);
}
