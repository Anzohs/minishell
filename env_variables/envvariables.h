/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvariables.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:15:20 by hladeiro          #+#    #+#             */
/*   Updated: 2024/12/26 21:28:27 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVVARIABLES_H
# define ENVVARIABLES_H

# include <unistd.h>

typedef char				*t_string;
typedef struct s_node		t_node;
typedef struct s_minishell	t_mini;

void	update_oldpwd(t_mini *m);
int		get_index(char **env, char *c, size_t len);
void	update_pwd(t_mini *m);
void	get_pwd(t_string s, int i);
void	get_export(t_mini *mini, t_node *command);
void	get_unset(t_mini *mini, t_node *command);
void	get_env(t_mini *mini, t_node *command);
void	get_echo(t_mini *mini, t_node *command);
int		ft_count(char **strs);
char	**add_env(char **strs, char *env);

#endif
