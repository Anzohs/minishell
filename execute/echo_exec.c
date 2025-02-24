/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:31:13 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/08 20:32:01 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static void	echo_new_line(t_string *matrix, int fd)
{
	int	i;

	i = -1;
	while (matrix[++i])
	{
		ft_putstr_fd(matrix[i], fd);
		if (matrix[i + 1])
			ft_putchar_fd(' ', fd);
	}
	ft_putendl_fd("", fd);
}

static void	echo_no_line(t_string *matrix, int fd)
{
	int	i;

	i = 0;
	while (matrix[++i])
	{
		ft_putstr_fd(matrix[i], fd);
		if (matrix[i + 1])
			ft_putchar_fd(' ', fd);
	}
}

static bool	new_line(t_string s)
{
	int	i;

	i = 0;
	if (!s || !*s || *s != '-' || s[1] != 'n')
		return (true);
	while (s[++i] == 'n')
		;
	return (!(s[i] == 0));
}

void	echo_exec(t_cmd *cmd)
{
	mini()->exit_code = 0;
	if (new_line(cmd->matrix[0]))
		return (echo_new_line(cmd->matrix, cmd->w));
	return (echo_no_line(cmd->matrix, cmd->w));
}
