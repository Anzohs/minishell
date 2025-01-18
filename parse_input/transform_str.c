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

void	transform_str(void)
{
	if (!is_valid())
	{
		ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
		printf("Not valid!\n");
		return ;
	}
	clean_content();
	ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
}
