/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_oldpwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:16:10 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/16 17:16:11 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	update_oldpwd(t_string path, t_list **lst)
{
	t_string	var;
	t_list		*new;

	if (!path)
		return ;
	var = ft_calloc(sizeof(char), ft_strlen(path) + 4);
	if (!var)
		exit(0);
	ft_strcpy(var, "OLD");
	ft_strcat(var, path);
	new = ft_lstnew(var);
	if (!new)
	{
		free(var);
		exit(0);
	}
	ft_lstadd_back(lst, new);
}
