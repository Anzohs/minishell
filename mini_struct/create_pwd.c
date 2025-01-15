/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 01:11:23 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/15 01:11:24 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_string	create_pwd(t_string s)
{
	t_string	pwd;

	if (!s)
		return (NULL);
	pwd = ft_calloc(sizeof(char), (ft_strlen(s) + 5));
	if (!pwd)
		return (NULL);
	ft_strcpy(pwd, "PWD=");
	ft_strcat(pwd, s);
	return (pwd);
}
