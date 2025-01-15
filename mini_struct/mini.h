/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:34:59 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/14 23:42:46 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "../minishell.h"

typedef struct s_cmd
{
	t_string		cmd;
	t_string		*arg;
	struct s_cmd	*next;
}					t_cmd;


typedef struct s_minishell
{
	char			*readline;
	char			*prompt;
	t_list			*env;
	t_list			*exp;
	t_hash			*ht;
	t_cmd			**cmd;
	int				pipes;
}					t_mini;

t_mini				*mini(void);
// env-exp list functions
// env-exp
t_string			create_pwd(t_string s);
void				m_copy_env(t_string env[]);
void				init_pwd(void);

#endif
