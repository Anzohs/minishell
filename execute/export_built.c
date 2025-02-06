/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_built.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:21:47 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/06 20:57:30 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static bool	add_exp(t_string s)
{
	if (*s == '=' || (!ft_isupper(*s) && !ft_islower(*s)))
	{
		ft_putstr_fd("export : ", 2);
		ft_putstr_fd(s, 2);
		ft_putendl_fd(": not a valid identifier", 2);
		return (false);
	}
	return (true);
}

static void	add_variables(t_string s, t_list **list)
{
	t_list	*current;
	t_string var_name;
	t_string var_value;
	char	*equal_sign;

	equal_sign = ft_strchr(s, '=');
	if (equal_sign)
	{
		var_name = ft_substr(s, 0, equal_sign - s);
		var_value = ft_strdup(equal_sign + 1);
	}
	else
	{
		var_name = ft_strdup(s);
		var_value = NULL;
	}

	current = *list;
	while (current)
	{
		if (ft_strncmp(current->content, var_name, ft_strlen(var_name)) == 0 &&
			(current->content[ft_strlen(var_name)] == '=' || current->content[ft_strlen(var_name)] == '\0'))
		{
			free(current->content);
			if (var_value)
				current->content = ft_strjoin(var_name, "=");
			else
				current->content = ft_strdup(var_name);
			if (var_value)
			{
				char *temp = current->content;
				current->content = ft_strjoin(current->content, var_value);
				free(temp);
			}
			free(var_name);
			free(var_value);
			return;
		}
		current = current->next;
	}

	if (var_value)
	{
		t_string new_var = ft_strjoin(var_name, "=");
		t_string new_content = ft_strjoin(new_var, var_value);
		ft_lstadd_back(list, ft_lstnew(new_content));
		free(new_var);
	}
	else
	{
		ft_lstadd_back(list, ft_lstnew(ft_strdup(var_name)));
	}
	free(var_name);
	free(var_value);
}

void	export_built(t_string *matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
	{
		if (add_exp(matrix[i]))
		{
			if (ft_strchr(matrix[i], '='))
				add_variables(matrix[i], &mini()->env);
			add_variables(matrix[i], &mini()->exp);
		}
	}
}
