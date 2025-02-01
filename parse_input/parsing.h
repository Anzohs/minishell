/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:56:50 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/01 18:49:47 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libs.h"

void	parse_input(void);
bool	is_valid(void);
void	clean_content(void);
void	clean_args(void);
bool	closed_quotes(t_string s);
void	clean_quotes(t_string *s);
bool	is_expantion(t_string s);
void	expantions(t_string *s);
bool	has_quotes(t_string *s);
t_string	sub_expantion(t_string s, t_string str);
void	transform_str(void);
t_string	*split_value(t_string str);
bool	split_need(t_string s);
void	take_quotes(t_string *str);
void	free_matrix(t_string *s);

#endif
