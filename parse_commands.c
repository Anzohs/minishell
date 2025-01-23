/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:21:26 by malourei          #+#    #+#             */
/*   Updated: 2025/01/23 21:57:53 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_commands(t_mini *mini, t_node *commands)
{
	t_node	*m;

	m = commands;
	if (node_len(m) < 1 || !clean_command(mini) || !clean_node(commands))
		return ;
	//printf("MACHO: %s\n", commands->entry.args[0]);
	if (commands->entry.args[0] && !ft_strcmp(commands->entry.args[0], "<<"))
		start_here_doc(m->entry.key, commands->entry.args, mini->super_env);
	else if (is_biltin(commands) && node_len(commands) == 1)
	{
		if (!ft_strcmp(m->entry.key, "cd"))
			cd_biltin();
		if (!ft_strcmp(m->entry.key, "pwd"))
			get_pwd(getcwd(NULL, 0), 0);
		if (!ft_strcmp(m->entry.key, "export"))
			get_export(mini, m);
		if (!ft_strcmp(m->entry.key, "unset"))
			get_unset(mini, m);
		if (!ft_strcmp(m->entry.key, "env"))
			get_env(mini, m);
		if (!ft_strcmp(m->entry.key, "echo"))
			get_echo(mini, m);
	}
	else
		pipex(mini, m);
}
