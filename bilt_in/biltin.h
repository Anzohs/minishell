/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:15:57 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/11 16:17:38 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BILTIN_H
# define BILTIN_H

# include <stdbool.h>

typedef struct s_node	t_node;

bool					is_biltin(t_node *n);
void					cd_biltin(void);

#endif
