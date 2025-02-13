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
	ft_lstadd_back(&mini()->env, ft_lstnew(ft_strdup("SHLVL=1")));
	ft_lstadd_back(&mini()->env, ft_lstnew(ft_strdup("_=usr/bin/env")));
	ft_lstadd_back(&mini()->exp, ft_lstnew(ft_strdup("OLDPWD")));
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
