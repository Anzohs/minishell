/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:17:04 by hladeiro          #+#    #+#             */
/*   Updated: 2024/12/14 16:34:24 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLEAN_H
# define FT_CLEAN_H

# include "../libs.h"

typedef struct s_node	t_node;

void	free_node(t_node *n);
void	free_env(char **c);

#endif
