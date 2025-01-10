/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:44:03 by hladeiro          #+#    #+#             */
/*   Updated: 2024/12/22 15:54:47 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_STR_H
# define VALID_STR_H

# include <stdbool.h>

typedef char				*t_string;
typedef struct s_minishell	t_mini;
typedef struct s_node		t_node;

bool						clean_command(t_mini *m);
bool						closed_quotes(t_string str);
bool						clean_node(t_node *n);
#endif
