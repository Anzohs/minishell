/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:59:58 by malourei          #+#    #+#             */
/*   Updated: 2024/11/14 17:59:31 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	validate_args(int argc, char **argv, int *cmd_argc)
{
	int	i;

	if (argc < 5)
	{
		write(2, "Error: Argumentos invalidos!\n", 29);
		exit(1);
	}
	i = 2;
	while (i < (argc - 1))
	{
		if (ft_only_space(argv[i]) == 0)
		{
			write(2, "Error: Comandos vazios!\n", 24);
			exit(1);
		}
		i++;
	}
	*cmd_argc = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc > 5)
		*cmd_argc = 3;
	else if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		write(2, "Error: Argumentos here_doc invalido!\n", 38);
		exit(1);
	}
}

void	count_pids(t_pipex *pipex, int argc)
{
	pipex->pids = malloc(sizeof(int) * argc);
	if (pipex->pids == NULL)
	{
		perror("malloc1");
		exit(1);
	}
	pipex->paths = malloc(sizeof(char *) * argc + 1);
	if (pipex->paths == NULL)
	{
		perror("malloc2");
		free(pipex->pids);
		exit(1);
	}
	pipex->fds = malloc(sizeof(t_fds) * (argc - 1));
	if (pipex->fds == NULL)
	{
		perror("malloc3");
		exit(1);
	}
}
