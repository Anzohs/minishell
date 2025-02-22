/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:48:28 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/22 21:55:31 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	take_redirect(t_string str)
{
		
}

void	redirects_parsing(void)
{
		int	i;

		i = -1;
		while(mini()->matrix[++i])
				take_redirect(mini()->matrix[i]);
}
