/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:38:55 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/27 23:24:53 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "execute.h"

int	execute_builtin(t_cmd *cmd, int fd, int i)
{
	if (!ft_strcmp(cmd->cmd, "cd"))
		cd_execute(cmd->matrix, fd);
	if (!ft_strcmp(cmd->cmd, "pwd"))
		pwd_execute(fd);
	if (!ft_strcmp(cmd->cmd, "env"))
		env_execute(fd);
	if (!ft_strcmp(cmd->cmd, "unset"))
		unset_execute(cmd);
	if (!ft_strcmp(cmd->cmd, "echo"))
		(echo_exec(cmd));
	if (!ft_strcmp(cmd->cmd, "export"))
	{
		if (!cmd->matrix || !cmd->matrix[0] || !*cmd->matrix[0])
			(export_print(fd));
		else
			(export_built(cmd->matrix));
	}
	if (i || !ft_strcmp(cmd->cmd, "exit"))
		return (exit_minishell(), 1);
	return (1);
}
