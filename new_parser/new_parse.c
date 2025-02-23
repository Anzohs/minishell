/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:44:29 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/23 18:02:18 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:17:54 by hladeiro          #+#    #+#             */
/*   Upated: 2025/02/22 21:31:37 by hladeiro         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "new_parse.h"

static void	mark_pipes(void)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (mini()->readline[++i])
	{
		if ((mini()->readline[i] == '\'' || mini()->readline[i] == '"') && !c)
			c = mini()->readline[i];
		else if (c == mini()->readline[i])
			c = 0;
		else if (mini()->readline[i] == '|' && !c)
			mini()->readline[i] = 2;
	}
}

static int	count_pipes(void)
{
	int	i;
	int	pipes;

	i = -1;
	pipes = 0;
	while (mini()->readline[++i])
	{
		if (mini()->readline[i] == 2)
			pipes++;
	}
	return (pipes);
}

static bool	check_errors(t_string *s)
{
	int	i;

	if (matrix_len(s) == 1 && !*s[0])
		return (free_env(s), true);
	i = -1;
	while (s[++i])
	{
		if (!*s[i])
			return (\
		ft_putendl_fd("bash: syntax error near unexpected token `|'",
					2), free_env(s), true);
	}
	return (false);
}

void	new_parse(void)
{
	t_string	*s;
	int			i;

	i = -1;
	if (!*mini()->readline || !closed_quotes(mini()->readline))
		return ;
	mark_pipes();
	s = ft_split(mini()->readline, 2);
	if (matrix_len(s) <= count_pipes())
		return (ft_putendl_fd("bash: syntax error near unexpected token `|'",
				2), free_env(s));
	while (s[++i])
	{
		trim_spaces(&s[i]);
		trim_front_spaces(&s[i]);
	}
	if (check_errors(s))
		return ;
	mini()->matrix = s;
	matrix_to_cmd();
}
