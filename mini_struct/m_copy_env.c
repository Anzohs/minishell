/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_copy_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 01:20:05 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/15 01:29:29 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	create_env(void)
{
	init_pwd();
   	//_=usr/bin/env
    //SHELLVL
}

static void	copy_env(t_string env[])
{
	int			i;
	t_string	var;
	t_list		*lst;

	i = -1;
	while (env[++i])
	{
		var = ft_strdup(env[i]);
		if (!var)
			exit(0);
		lst = ft_lstnew(var);
		if (!lst)
		{
			free(var);
			//t_exit(0);
			exit(0);
		}
		ft_lstadd_back(&mini()->env, lst);
	}
}

void	m_copy_env(t_string env[])
{
	if (!env || !*env)
		create_env();
	else
		copy_env(env);
}
