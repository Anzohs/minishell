/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:51:34 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/04 16:48:16 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../libs.h"

typedef struct s_cmd	t_cmd;

void					execute(void);
void					cd_execute(t_string *matrix, int fd);
void					pwd_execute(int fd);
void					export_print(int fd);
void					export_built(t_string *matrix);
void					env_execute(int fd);
void					unset_execute(t_cmd *cmd);
void					echo_exec(t_cmd *cmd);
int						execute_builtin(t_cmd *cmd, int fd, int i);
void					exit_minishell(void);

#endif
