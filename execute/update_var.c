/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:26:06 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/04 19:27:10 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

void	update_existing_var(t_list *current, t_string var_name,
		t_string var_value)
{
	char	*temp;

	free(current->content);
	if (var_value)
		current->content = ft_strjoin(var_name, "=");
	else
		current->content = ft_strdup(var_name);
	if (var_value)
	{
		temp = current->content;
		current->content = ft_strjoin(current->content, var_value);
		free(temp);
	}
}
