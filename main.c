/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:57:48 by malourei          #+#    #+#             */
/*   Updated: 2024/11/25 22:20:25 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_search/ft_search.h"
#include "minishell.h"

void	print_hash_table(t_hash *ht)
{
	t_node	*node;
	size_t	i;

	if (!ht)
		return ;
	i = -1;
	while (++i < ht->len)
	{
		node = ht->node[i];
		while (node)
		{
			printf("Command: %s, Arguments: %s\n", node->entry.key,
				(char *)node->entry.value);
			node = node->next;
		}
	}
}

void	printf_evn(char **env)
{
	int	i;

	i = 0;
	if (!env)
		exit(1);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

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
		free(n);
		n = tmp;
	}
}

void	print_node(t_node *n)
{
	t_node	*node = n;
	while (node)
	{
		printf("Command: %s, Arguments: %s\n", node->entry.key,
			(char *)node->entry.value);
		node = node->next;
	}
}

int	main(int ac, char **av, char **env)
{
	static t_mini	m;
	// t_hash			*ht;

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
		parse_input(m.ht, m.readline);
		add_history(m.readline);
		print_hash_table(m.ht);
		if (!ft_strcmp(m.readline, "pwd"))
		{
			// fazer update do pwd
			// getcwd(NULL, 1);
		}
		if (!ft_strcmp(m.readline, "cd"))
		{
			// faz so o absolute path (cd) e prepara para receber o parsing!
			// update ao pwd, e ao old pwd
		}
		free(m.readline);
		m.readline = readline(m.prompt);
	}
	rl_clear_history();
	free_all(m.super_env);
	hdestroy(m.ht);
	return (0);
}
// valgrind --suppressions=read.supp --show-leak-kinds=all --leak-check=full
