/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:33:10 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/23 16:33:49 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_PARSE_H
# define NEW_PARSE_H

# include "../libs.h"

void		new_parse(void);
void		matrix_to_cmd(void);
void		redirects_parsing(void);
t_string	new_cut(t_string *s, int init, int end);
void		trim_spaces(t_string *s);
void		trim_front_spaces(t_string *s);
void		expantion_mark(void);
#endif
