/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:34:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/02 21:38:20 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_str(char *str)
{
	int	length;

	length = strlen(str);
	if (str[0] == '"' || str[0] == '\'')
	{
		memmove(str, str + 1, length - 1);
		length--;
	}
	if ((str[length - 1] == '"' || str[length - 1] == '\'') && length > 0)
	{
		str[length - 1] = '\0';
			// Null-terminate the string to remove the last character
	}
}
