/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/19 15:11:10 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	transform_str(void)
{
	if (!is_valid())
	{
		ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
		printf("Not valid!\n");
		return ;
	}
	clean_content();
	if (mini()->cmd->cmd && *mini()->cmd->cmd)
		execute();
}
