/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:53:48 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/12 14:53:49 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
static void prin(char *s) {
	int i;

	i = -2;
	if (!s || !*s) {
		printf("Error\n");
	}
	printf("%s\n", s);
}
void	parse_node(t_node **n)
{
	t_node	*tmp;
	int		i;

	tmp = *n;
	i = -1;
	while (tmp) {
		expations(&tmp->entry.key, (t_string *)&tmp->entry.value);
		tmp->entry.args = split_value((t_string)tmp->entry.value);
		if (is_expantion(tmp->entry.key) && has_quotes(tmp->entry.key))
			tmp->entry.key = expand_args(tmp->entry.key);
		else if (is_expantion(tmp->entry.key))
			expand_cmd(tmp->entry.key, tmp->entry.args);
		while (tmp->entry.args && tmp->entry.args[++i])
		{
			prin(tmp->entry.args[i]);
			if (is_expantion(tmp->entry.args[i]))
				tmp->entry.args[i] = expand_args(tmp->entry.args[i]);
		}
		tmp = tmp->next;
	}
}
