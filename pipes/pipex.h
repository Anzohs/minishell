/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:44:14 by malourei          #+#    #+#             */
/*   Updated: 2024/12/29 17:03:28 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs.h"
# include <stddef.h>

typedef struct s_minishell	t_mini;
typedef struct s_node		t_node;

typedef struct s_fds
{
	int	fd[2];
}	t_fds;

typedef struct s_pipex
{
	int		in_file;
	int		out_file;
	t_fds	*fds;
	int		*pids;
	int		argc;
	int		cmd_argc;
	int		is_doc;
	int		i_multi_argv;
	char	**paths;
	char	*path2;
	char	**env;
	char	**cmd1;
	char	**cmd2;
}	t_pipex;

void	validate_args(t_node *argv, int *cmd_argc);
void	ft_child_one(t_pipex *pipex, char **env, char *cmd_path, t_node *node);
void	ft_child_two(t_pipex *pipex, char **env, char *cmd_path, t_node *node);
void	clean_pointer(char **strs);
void	ft_close(int fd);
void	find_full_cmd(t_pipex *pipex, t_mini *mini, t_node *node);
void	ft_parent(t_pipex *pipex);
void	clean_all(t_pipex *pipex);
void	ft_clean_path(t_pipex *pipex, char *path);
void	execve2(const char *path, t_node *node, char *const envp[]);
void	ft_close_all_p(t_pipex *pipex);
void	ft_close_all_1(t_pipex *pipex);
void	ft_close_all_m(t_pipex *pipex, int i);
void	clean_null_env(t_pipex *pipex);
void	count_pids(t_pipex *pipex, int argc);
void	ft_child_doc_one(t_pipex *pipex, char **env, char *cmd_path, t_node *n);
void	start_here_doc(t_pipex *pipex, t_node *n);
void	start_in_file(t_pipex *pipex);
void	pipex(t_mini *mini, t_node *comands);

#endif
