/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:44:14 by malourei          #+#    #+#             */
/*   Updated: 2024/09/24 22:59:37 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>

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

void	validate_args(int argc, char **argv, int *cmd_argc);
void	ft_child_one(t_pipex *pipex, char **env, char *cmd_path);
void	ft_child_two(t_pipex *pipex, char **env, char *cmd_path);
void	clean_pointer(char **strs);
void	ft_close(int fd);
void	find_full_cmd(t_pipex *pipex, char **env, char **argv);
void	ft_parent(t_pipex *pipex);
void	clean_all(t_pipex *pipex);
void	ft_clean_path(t_pipex *pipex, char *path);
void	execve2(const char *path, char *const argv[], char *const envp[]);
void	ft_close_all_p(t_pipex *pipex);
void	ft_close_all_1(t_pipex *pipex);
void	ft_close_all_m(t_pipex *pipex, int i);
void	clean_null_env(t_pipex *pipex);
void	count_pids(t_pipex *pipex, int argc);
void	ft_child_doc_one(t_pipex *pipex, char **env, char *cmd_path);
void	start_here_doc(t_pipex *pipex, char *argV[]);
void	start_in_file(t_pipex *pipex, char *argV[]);

#endif
