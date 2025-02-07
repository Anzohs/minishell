/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/04 21:22:26 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../libs.h"

typedef struct s_cmd    t_cmd;

void	execute(void);
void	cd_execute(t_string *matrix);
void	pwd_execute(void);
void	export_print(void);
void	export_built(t_string *matrix);
void    env_execute(void);
void    unset_execute(t_cmd *cmd);


#endif
