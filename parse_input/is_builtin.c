/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:45:31 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/02 17:46:25 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_builtin(t_string s)
{
	return (!ft_strcmp(s, "echo") || !ft_strcmp(s, "cd") || !ft_strcmp(s,
			"export") || !ft_strcmp(s, "unset") || !ft_strcmp(s, "env")
		|| !ft_strcmp(s, "pwd"));
}
