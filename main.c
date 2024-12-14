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

#include "ft_clean/ft_clean.h"
#include "minishell.h"

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
	static t_mini	m;

	(void)av;
	if (ac > 1)
		return (0);
	m.super_env = NULL;
	if (*env)
		copy_env(&m, env);
	else
		creat_env(&m);
	m.prompt = "shell > ";
	m.readline = readline(m.prompt);
	m.ht = hcreate(10);
	while (m.readline && ft_strcmp(m.readline, "exit"))
	{
		parse_input(m.ht, m.readline, &m);
		add_history(m.readline);
		parse_commands(&m, m.commands);
		free_node(m.commands);
		m.commands = NULL;
		free(m.readline);
		m.readline = readline(m.prompt);
	}
	// rl_clear_history() ;
	free_env(m.super_env);
	hdestroy(m.ht);
	return (0);
}
// valgrind --suppressions=read.supp --show-leak-kinds=all --leak-check=full
