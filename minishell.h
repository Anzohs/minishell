/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:01:09 by malourei          #+#    #+#             */
/*   Updated: 2025/01/11 12:23:44 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "env_variables/envvariables.h"
# include "ft_clean/ft_clean.h"
# include "ft_search/ft_search.h"
# include "pipes/pipex.h"
# include "libs.h"

typedef struct s_minishell
{
	char	*c;
	char	*readline;
	char	*prompt;
	char	**super_env;
	t_hash	*ht;
	t_node	*commands;
	int		pipes;
}			t_mini;

void		copy_env(t_mini *mini, char **env);
void		ft_free_strs(char **strs, int size);
void		creat_env(t_mini *mini);
void		parse_input(t_hash *ht, const char *input, t_mini *m);
void		parse_commands(t_mini *mini, t_node *commands);
t_mini		*mini(void);
#endif
