/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:57:48 by malourei          #+#    #+#             */
/*   Updated: 2024/12/14 16:39:12 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <time.h>

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}


int	main(int ac, char **av, char **env)
{
	mini()->super_env = NULL;
	(void)av;
	if (ac > 1)
		return (0);
	if (*env)
		copy_env(mini(), env);
	else
		creat_env(mini());
	mini()->prompt = "shell > ";
	mini()->readline = readline(mini()->prompt);
	mini()->ht = hcreate(10);
	while (mini()->readline && ft_strcmp(mini()->readline, "exit"))
	{
		parse_input(mini()->ht, mini()->readline, mini());
		add_history(mini()->readline);
		parse_commands(mini(), mini()->commands);
		free_node(mini()->commands);
		mini()->commands = NULL;
		free(mini()->readline);
		mini()->readline = readline(mini()->prompt);
	}
	// rl_clear_history() ;
	free_env(mini()->super_env);
	hdestroy(mini()->ht);
	return (0);
}
// valgrind --suppressions=read.supp --show-leak-kinds=all --leak-check=full
