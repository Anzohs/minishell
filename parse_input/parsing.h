/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:56:50 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/16 21:08:28 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libs.h"

void	parse_input(void);
bool	is_valid(void);
void	clean_args(void);
bool	closed_quotes(t_string s);
void	clean_quotes(t_string *s);
void	is_expantion(t_string s);
void	expantios(t_string *s);
void	has_quotes(t_string *s);
void	transform_str(void);
#endif
