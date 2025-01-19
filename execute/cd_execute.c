/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:02:55 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/19 19:47:33 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include <stdio.h>

static void	home(void)
{
	t_string	s;
	int			i;

	s = ft_lsthas(mini()->env, "HOME=");
	if (!s || !*s)
	{
		perror("Home not set");
		return ;
	}
	s++;
	i = chdir(s);
	if (i == -1)
		perror("CD");
}

static int	l(t_string *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		;
	return (i);
}

void	cd_execute(void)
{
	t_string	s;

	if (l(mini()->cmd->matrix) > 1)
		return (perror("Too many arguments"), (void)s);
	if (!mini()->cmd->arg || !*mini()->cmd->arg || \
		!ft_strcmp(mini()->cmd->matrix[0], "") || \
		!ft_strcmp(mini()->cmd->matrix[0], "~"))
		home();
	else if (chdir(mini()->cmd->matrix[0]) < 0)
		return (perror(mini()->cmd->arg), (void)s);
	else if (!ft_strcmp(mini()->cmd->matrix[0], "-"))
		return ;
	else if (chdir(mini()->cmd->matrix[0]) >= 0)
		return ;
	s = getcwd(NULL, 0);
	printf("%s \n", s);
	free(s);
}
