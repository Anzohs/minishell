/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:57:48 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/13 23:05:19 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	parsing(char *c)
{
	printf("%s \n", c);
}

void	printf_evn(char **env)
{
	int	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	static t_mini	m;
	char		**super_env;

	if (ac > 1)
		return 0;
	/* if (*env)
		copy_env(env, super_env);
	else
		create_env(super_env);
	inti_minishel(super_env); */
	//teste
	// ze novo teste
	m.prompt = "shell > ";
	m.readline = readline(m.prompt);
	printf_evn(env);
	while (m.readline  && str_cpm(m.readline, "exit"))
	{
		parsing(m.readline);
		free(m.readline);
		m.readline = readline(m.prompt);
	}
	free(m.c);
	return 1;
}
//valgrind --suppressions=read.supp --show-leak-kinds=all --leak-check=full
