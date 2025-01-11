/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:37:22 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/11 12:37:23 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_biltin(t_node *n)
{
	return (!ft_strcmp(n->entry.key, "cd") || !ft_strcmp(n->entry.key, "echo")
		|| !ft_strcmp(n->entry.key, "exit") || !ft_strcmp(n->entry.key, "env")
		|| !ft_strcmp(n->entry.key, "export") || !ft_strcmp(n->entry.key, "pwd")
		|| !ft_strcmp(n->entry.key, "unset"));
}
