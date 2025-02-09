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

void	execute_builtin(t_cmd *cmd, int fd)
{
	if (!ft_strcmp(cmd->cmd, "cd"))
		return (cd_execute(cmd->matrix, fd));
	if (!ft_strcmp(cmd->cmd, "pwd"))
		return (pwd_execute(fd));
	if (!ft_strcmp(cmd->cmd, "env"))
		return (env_execute(fd));
	if (!ft_strcmp(cmd->cmd, "unset"))
		return (unset_execute(cmd));
	if (!ft_strcmp(cmd->cmd, "echo"))
		return (echo_exec(cmd));
	if (!ft_strcmp(cmd->cmd, "export"))
	{
		if (*cmd->arg)
			return (export_built(cmd->matrix));
		return (export_print(fd));
	}
	return ;
}
