/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:19:47 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/02 20:09:32 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	pwd_execute(void)
{
	t_string	m;

	m = getcwd(NULL, 0);
	printf("%s \n", m);
	free(m);
}
