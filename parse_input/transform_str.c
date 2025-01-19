/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:51:41 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/18 15:51:42 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	printf_list(t_cmd *lst)
{
	t_cmd	*l;
	int		i;

	l = lst;
	i = -1;
	while (l)
	{
		printf("cmd : %s \n", l->cmd);
		printf("arg : %s \n", l->arg);
		while (l->matrix[++i])
			printf("matix[%i] : %s\n", i, l->matrix[i]);
		i = -1;
		l = l->next;
	}
}

void	transform_str(void)
{
	if (!is_valid())
	{
		ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
		printf("Not valid!\n");
		return ;
	}
	clean_content();
	execute();
}
