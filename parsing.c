#include "ft_search/ft_search.h"
#include "minishell.h"

static t_string	extract_arg(const char *input, size_t *index)
{
	while (input[*index] && (input[*index] == ' ' || input[*index] == '\t')) {
        (*index)++;
    }
    size_t start = *index;
    int in_quotes = 0;
    while (input[*index] && (input[*index] != '|' || in_quotes)) {
        if (input[*index] == '"' || input[*index] == '\'') {
            in_quotes = !in_quotes;
        }
        (*index)++;
    }
    size_t len = *index - start;
    char *arguments = (char *)malloc(len + 1);
    if (!arguments) {
        return NULL;
    }
    strncpy(arguments, input + start, len);
    arguments[len] = '\0';
    return arguments;
}

static t_string	extract_command(const char *input, size_t *index)
{
	size_t start = *index;
    while (input[*index] && input[*index] != ' ' && input[*index] != '\t') {
        (*index)++;
    }
    size_t len = *index - start;
    char *command = (char *)malloc(len + 1);
    if (!command) {
        return NULL;
    }
    strncpy(command, input + start, len);
    command[len] = '\0';
    return command;
}

void	parse_input(t_hash *ht, const char *input)
{
	size_t		index;
	t_string	command;
	t_string	arg;

	index = 0;
    while (input[index]) {
        command = extract_command(input, &index);
        if (!command)
        	return;
        arg = extract_arg(input, &index);
        if (!arg)
        {
            free(command);
            return;
        }
        t_entry entry = { command, arg};
        hsearch(ht, entry, ENTER);
        while (input[index] && (input[index] == ' ' || input[index] == '\t' || input[index] == '|')) {
            index++;
        }
    }
}
