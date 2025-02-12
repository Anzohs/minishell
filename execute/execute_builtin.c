/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:38:55 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/09 18:04:52 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

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
		if (*cmd->arg)
			(export_built(cmd->matrix));
		else
			(export_print(fd));
	}
	if (i)
		return (exit(0), 1);
	return (1);
}
