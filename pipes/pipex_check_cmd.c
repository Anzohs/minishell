/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:52:33 by malourei          #+#    #+#             */
/*   Updated: 2025/03/02 00:00:59 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

bool	check_command(t_cmd *tmp, char *cmd_path)
{
	if (!is_builtin(tmp->cmd) && access(cmd_path, F_OK) != 0)
		return (ft_putendl_fd("command not found", STDERR_FILENO),
				false);
	if (!good_files(tmp) || !*tmp->cmd)
		return (false);
	return (true);
}
