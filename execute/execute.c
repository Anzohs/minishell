/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/01 19:06:10 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static bool	is_builtin(t_string s)
{
	return (!ft_strcmp(s, "echo") || \
		!ft_strcmp(s, "cd") || \
		!ft_strcmp(s, "export") || \
		!ft_strcmp(s, "unset") || \
		!ft_strcmp(s, "env") || \
		!ft_strcmp(s, "pwd"));
}

static void p(t_string *s)
{
	int i = 0;

	while (s[i])
		printf("%s \n", s[i++]);
}

static void prin()
{
	t_cmd *c = mini()->cmd;
	while(c)
	{
		p(c->matrix);
		c = c->next;
	}
}

void	execute(void)
{
	if (!mini()->cmd->cmd || !*mini()->cmd->cmd)
		return ;
	if (ft_cmdlst_len(&mini()->cmd) == 1 && is_builtin(mini()->cmd->cmd))
	{
		if (!ft_strcmp(mini()->cmd->cmd, "cd"))
			return (cd_execute());
		if (!ft_strcmp(mini()->cmd->cmd, "pwd"))
			return (pwd_execute());
		else
			printf("nao e cd\n");
	}
	else
		prin();
}
