/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:31:13 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/04 21:07:19 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static void	unset_exp(t_list *lst, t_string s)
{
	while (lst)
	{
		if (ft_strlen(lst->content) >= ft_strlen(s) &&
			(lst->content[ft_strlen(s)] == '='
			|| lst->content[ft_strlen(s)] == 0))
			return (ft_lstpop(&mini()->exp, lst));
		lst = lst->next;
	}
}

static void	unset_env(t_list *lst, t_string s)
{
	while (lst)
	{
		
		if (ft_strlen(lst->content) >= ft_strlen(s) &&
			(lst->content[ft_strlen(s)] == '='))
			return (ft_lstpop(&mini()->env, lst));
		lst = lst->next;
	}
}

void	unset_execute(t_cmd *cmd)
{
	int		i;
	t_list	*env_node;
	t_list	*exp_node;

	if (!cmd->matrix || !*cmd->matrix[0])
		return ;
	i = -1;
	while (cmd->matrix[++i])
	{
		env_node = ft_lstgetlst(&mini()->env, cmd->matrix[i]);
		if (env_node)
			unset_env(env_node, cmd->matrix[i]);
		exp_node = ft_lstgetlst(&mini()->exp, cmd->matrix[i]);
		if (exp_node)
			unset_exp(exp_node, cmd->matrix[i]);
	}
	mini()->exit_code = 0;
}
