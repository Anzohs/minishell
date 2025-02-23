/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by malourei          #+#    #+#             */
/*   Updated: 2025/02/09 19:22:25 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "execute.h"
#include <fcntl.h>
#include <string.h>

static bool	ret(t_cmd *cmd)
{
	if (!cmd)
		return (true);
	return (ft_putstr_fd("Error near >", 2), false);
}

static bool	check_redirects(t_cmd **cmd)
{
	t_cmd	*temp;

	temp = *cmd;
	while (temp)
	{
		if (temp->fd)
		{
			if (!change_fd(&temp))
				return (false);
		}
		temp = temp->next;
	}
	return (ret(temp));
}

static t_string	*new_matrix(t_string *matrix)
{
	int			i;
	t_string	*s;
	int			j;

	i = matrix_len(matrix);
	if (!i)
		return (free_env(matrix), NULL);
	s = ft_calloc(i, sizeof(t_string));
	if (!s)
		return (free_env(matrix), NULL);
	j = 0;
	while (++j < i)
		s[j - 1] = ft_strdup(matrix[j]);
	return (free_env(matrix), s);
}

static void	new_cmd(t_cmd **cmd)
{
	t_cmd	*lst;

	lst = *cmd;
	free(lst->cmd);
	lst->cmd = ft_strdup(lst->matrix[0]);
	lst->matrix = new_matrix(lst->matrix);
}

static void	change_cmd(t_cmd **cmd)
{
	t_cmd	*lst;

	lst = *cmd;
	while (lst)
	{
		new_cmd(&lst);
		lst = lst->next;
	}
}

void	execute(void)
{
	change_cmd(&mini()->cmd);
	if (!check_redirects(&mini()->cmd))
		return ;
	else if (ft_cmdlst_len(&mini()->cmd) == 1 && is_builtin(mini()->cmd->cmd))
		execute_builtin(mini()->cmd, mini()->cmd->w, 0);
	else
		pipex();
}
