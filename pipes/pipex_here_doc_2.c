/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:52:43 by malourei          #+#    #+#             */
/*   Updated: 2025/02/23 14:59:57 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"

void	here_doc_2(char *limiter, int fd[2])
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	ft_close(fd[1]);
	return ;
}
