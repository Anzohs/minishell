/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:57:48 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/18 20:13:30 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_search/ft_search.h"
#include "minishell.h"

static int	str_cpm(char *c, char *d)
{
	int	i;

	i = 0;
	while (c[i] == d[i] && d[i])
		i++;
	if (d[i] == c[i])
		return (0);
	return (1);
}

void print_hash_table(t_hash *ht) {
    if (!ht) {
        return;
    }
    for (size_t i = 0; i < ht->len; i++) {
        t_node *node = ht->node[i];
        while (node) {
            printf("Command: %s, Arguments: %s\n", node->entry.key, (char *)node->entry.value);
            node = node->next;
        }
    }
}

void	printf_evn(char **env)
{
	int	i;

	i = 0;
	if (!env)
		exit (1);
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

int	main(int ac, char **av, char **env)
{
	static t_mini	m;
	t_hash	*ht;

	(void)av;
	if (ac > 1)
		return (0);
	m.super_env = NULL;

	if (*env)
		copy_env(&m, env);
	else
		creat_env(&m);
	//inti_minishel(super_env);
	m.prompt = "shell > ";
	m.readline = readline(m.prompt);
	ht = hcreate(10);
	while (m.readline  && str_cpm(m.readline, "exit"))
	{
		parse_input(ht, m.readline);
		add_history(m.readline);
		print_hash_table(ht);
		if (!str_cpm(m.readline, "pwd"))
		{
			//fazer update do pwd
			// getcwd(NULL, 1);
		}
		if (!str_cpm(m.readline, "cd"))
		{
			//faz so o absolute path (cd) e prepara para receber o parsing!
			//update ao pwd, e ao old pwd

		}
		free(m.readline);
		m.readline = readline(m.prompt);
	}
	free_all(m.super_env);
	//free(m.c);
	return (0);
}
//valgrind --suppressions=read.supp --show-leak-kinds=all --leak-check=full
