/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:12:27 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/14 20:15:29 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	has_space(t_string s)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != ' ')
		;
	return (s[i] == ' ');
}

void	expand_cmd(t_string *cmd, t_string **args)
{
	t_string	new;
	t_string	*matrix;

	new = expand_args(*cmd);
	printf("line 31 %s \n", new);
	if (has_space(new)) {
		*cmd = ft_strdup(new);
		free(new);
	}
	else
	{
		matrix = ft_mysplit(new, ' ');
		*cmd = ft_strdup(matrix[0]);
		*args = join_matrix(matrix, *args);
		printf("%s \n", **args);
	}
}
