/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:46:45 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/26 20:28:22 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_string	extract_arg(const char *input, size_t *index)
{
	size_t	start;
	int		in_quotes;
	size_t	len;
	char	*arguments;

	while (input[*index] && (input[*index] == ' '))
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
	ft_strncpy(arguments, input + start, len);
	return (arguments);
}

static t_string	extract_command(const char *input, size_t *index)
{
	size_t	start;
	size_t	len;
	int		c;
	char	*command;

	c = 0;
	start = *index;
	while (input[*index] && (input[*index] != ' ' || c))
	{
		if ((input[*index] == '\'' || input[*index] == '"') && !c)
			c = input[*index];
		else if (c == input[*index])
			c = 0;
		(*index)++;
	}
	len = *index - start;
	command = ft_calloc(len + 1, sizeof(char));
	if (!command)
		return (NULL);
	printf("aqui \n");
	ft_strncpy(command, input + start, len);
	printf("command %s\n", command);
	return (command);
}

static t_node	*new_node(t_entry *e)
{
	t_node	*n;

	n = ft_calloc(sizeof(t_node), 1);
	if (!n)
		return (NULL);
	n->entry = (t_entry){0};
	n->entry.key = ft_strdup(e->key);
	n->entry.value = ft_strdup(e->value);
	n->next = NULL;
	return (n);
}

static t_node	*copy(t_mini *m, t_entry *e)
{
	t_node	*n;

	if (!m->commands)
		return (new_node(e));
	n = m->commands;
	while (n->next)
		n = n->next;
	n->next = new_node(e);
	return (m->commands);
}

// parse_input(const char *input)
void	parse_input(t_hash *ht, const char *input, t_mini *m)
{
	size_t		index;
	t_string	command;
	t_string	arg;
	t_entry		*entry;

	index = 0;
	while (input[index])
	{
		while (input[index] == ' ')
			index++;
		command = extract_command(input, &index);
		if (!command)
			return ;
		arg = extract_arg(input, &index);
		if (!arg)
		{
			free(command);
			return ;
		}
		entry = hsearch(ht, (t_entry){command, arg, NULL}, ENTER);
		while (input[index] && (input[index] == ' ' || input[index] == '\t'
				|| input[index] == '|'))
			index++;
		mini()->commands = copy(m, entry);
		free(command);
		free(arg);
	}
}
