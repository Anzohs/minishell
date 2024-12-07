/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:57:48 by malourei          #+#    #+#             */
/*   Updated: 2024/11/30 18:33:17 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_node(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	while (tmp)
	{
		tmp = tmp->next;
		free(n->entry.key);
		free(n->entry.value);
		free(n);
		n = tmp;
	}
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
	free_all(m.super_env);
	hdestroy(m.ht);
	return (0);
}
// valgrind --suppressions=read.supp --show-leak-kinds=all --leak-check=full
