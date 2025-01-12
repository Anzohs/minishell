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
void						expations(t_string *comm, t_string *arg);
void						clean_quotes(t_string *s);
void						parse_node(t_node **n);
t_string					expand_cmd(t_string cmd);
bool						has_quotes(t_string s);
bool						is_expantion(t_string s);
t_string					expand_args(t_string cmd);
t_string					*split_value(t_string str);

#endif
