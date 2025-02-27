/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:14:26 by malourei          #+#    #+#             */
/*   Updated: 2025/02/26 23:24:31 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include "../libs.h"
# include <stddef.h>
# include <sys/ioctl.h>
# include "../minishell.h"

typedef struct s_minishell	t_mini;
typedef struct s_cmd		t_cmd;
typedef	struct s_fd			t_fd;
typedef struct s_fds
{
	int	fd[2];
}	t_fds;

typedef struct s_pipex
{
	t_fds	*fds;
	int		*pids;
	int		argc;
	int		cmd_argc;
	int		is_doc;
	int		i_multi_argv;
	char	**paths;
	char	*path2;
	char	**env;
	char	**env_path;
	char	**cmd1;
}	t_pipex;

void		validate_args(t_cmd *argv, int *cmd_argc);
void		child_one(t_pipex *pipex, char **env, char *cmd_path, t_cmd *node);
void		ft_close(int fd);
bool		find_full_cmd(t_pipex *pipex, t_cmd *node);
void		ft_parent(t_pipex *pipex);
void		clean_all(t_pipex *pipex);
void		ft_clean_path(t_pipex *pipex, char *path);
void		execve2(const char *path, t_cmd *node, char *const envp[]);
void		ft_close_all_p(t_pipex *pipex);
void		ft_close_all_1(t_pipex *pipex);
void		ft_close_all_m(t_pipex *pipex, int i);
void		clean_null_env(t_pipex *pipex);
void		count_pids(t_pipex *pipex, int argc);
void		pipex(void);
void		child_two(t_pipex *pipex, char **env, char *cmd_path, t_cmd *node);
t_string	*fusion_strs(t_cmd *cmd);
void		free_env(char **strs);
void		create_arrow(t_cmd *node);
void		ft_close_all_files(t_cmd *cmd);
//void		here_doc_2(char *limiter, int fd);
void		clear_pipe(int fd[2]);
//void		check_here_doc(t_cmd *cmd);
void 		check_per_cmd(t_cmd *cmd);
int read_file_get_file (t_fd *f);
int write_file_get_file(t_fd *f);
/* void	one_arrow(t_cmd *m);
void	two_arrow(t_cmd *m);
void	one_arrow_reverse(t_cmd *m); */

#endif
