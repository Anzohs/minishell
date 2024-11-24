/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:46:45 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/24 20:06:28 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_search/ft_search.h"
#include "minishell.h"

static t_string	extract_arg(const char *input, size_t *index)
{
	size_t	start;
	int		in_quotes;
	size_t	len;
	char	*arguments;

	while (input[*index] && (input[*index] == ' ' || input[*index] == '\t'))
		(*index)++;
	start = *index;
	in_quotes = 0;
	while (input[*index] && (input[*index] != '|' || in_quotes))
	{
		if (input[*index] == '"' || input[*index] == '\'')
			in_quotes = !in_quotes;
		(*index)++;
	}
	len = *index - start;
	arguments = (char *)ft_calloc(len + 1, sizeof(char));
	if (!arguments)
		return (NULL);
	strncpy(arguments, input + start, len);
	return (arguments);
}

static t_string	extract_command(const char *input, size_t *index)
{
	size_t	start;
	size_t	len;
	char	*command;

	start = *index;
	while (input[*index] && input[*index] != ' ' && input[*index] != '\t')
		(*index)++;
	len = *index - start;
	command = ft_calloc(len + 1, sizeof(char));
	if (!command)
		return (NULL);
	strncpy(command, input + start, len);
	return (command);
}

static t_node	*get_last(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_calloc(sizeof(t_node), 1);
	return (tmp->next);
}

void	parse_input(t_hash *ht, const char *input, t_node *n)
{
	size_t		index;
	t_string	command;
	t_string	arg;

	index = 0;
	while (input[index])
	{
		command = extract_command(input, &index);
		if (!command)
			return ;
		arg = extract_arg(input, &index);
		if (!arg)
		{
			free(command);
			return ;
		}
		if (!n->entry.key)
			n->entry = *hsearch(ht, (t_entry){command, arg}, ENTER);
		else
			get_last(n)->entry = *hsearch(ht, (t_entry){command, arg}, ENTER);
		while (input[index] && (input[index] == ' ' || input[index] == '\t'
				|| input[index] == '|'))
			index++;
		free(command);
		free(arg);
	}
}
