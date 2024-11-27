/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:01:09 by malourei          #+#    #+#             */
/*   Updated: 2024/11/26 19:08:08 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_search/ft_search.h"

typedef struct s_minishell
{
	char	*c;
	char	*readline;
	char	*prompt;
	char	**super_env;
	t_hash	*ht;
	t_node	*commands;
	int		pipes;
}		t_mini;

void	copy_env(t_mini *mini, char **env);
void	ft_free_strs(char **strs, int size);
void	creat_env(t_mini *mini);	
void	parse_input(t_hash *ht, const char *input, t_mini *m);
void	parse_commands(t_mini *mini, t_node *commands);

#endif
