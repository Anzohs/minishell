/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:19:47 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/08 20:40:51 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	pwd_execute(int fd)
{
	t_string	m;

	m = getcwd(NULL, 0);
	ft_putendl_fd(m, fd);
	free(m);
	mini()->exit_code = 0;
}
