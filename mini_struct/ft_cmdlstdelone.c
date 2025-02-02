/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdlstdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:29:51 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/01 18:50:35 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_cmdlstdelone(t_cmd **lst)
{
	t_cmd	*temp;

	temp = *lst;
	if (temp->arg)
		free(temp->arg);
	if (temp->cmd)
		free(temp->cmd);
	free_matrix(temp->matrix);
	free(temp);
}
