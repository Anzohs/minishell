/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:01:09 by hladeiro          #+#    #+#             */
/*   Updated: 2024/11/18 23:16:29 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./src/libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_minishell
{
	char	*c;
	char	*readline;
	char	*prompt;
	char	**super_env;
	int		pipes;
}		t_mini;

void	copy_env(t_mini *mini, char **env);
void	ft_free_strs(char **strs, int size);
void	creat_env(t_mini *mini);

#endif
