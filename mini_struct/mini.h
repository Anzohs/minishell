/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:34:59 by malourei          #+#    #+#             */
/*   Updated: 2025/03/05 21:04:16 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "../minishell.h"

typedef enum s_type
{
	APPEND,
	CREATE,
	HEREDOC,
	REVERSE,
}					t_type;

typedef struct s_fd
{
	int				fd;
	t_string		name;
	t_type			type;
	struct s_fd		*next;
}					t_fd;

typedef struct s_cmd
{
	t_string		cmd;
	t_string		arg;
	t_string		*matrix;
	t_string		*arrow;
	t_fd			*fd;
	int				w;
	int				read;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_minishell
{
	t_string		*matrix;
	char			*readline;
	char			*prompt;
	t_list			*env;
	t_list			*exp;
	t_cmd			*cmd;
	t_pipex			*pipex;
	int				pipes;
	int				start;
	int				sig;
	int				exit_code;
	struct stat		stat;
}					t_mini;

t_mini				*mini(void);
// env-exp list functions
// env-exp
t_string			create_pwd(t_string s);
void				m_copy_env(t_string env[]);
void				init_pwd(void);
t_cmd				*ft_cmdlst_new(char *cmd, char *arg);
void				ft_cmdlstadd_back(t_cmd **lst, t_cmd *n);
void				ft_cmdlstclear(t_cmd **lst, void (*del)(t_cmd **lst));
void				ft_cmdlstdelone(t_cmd **lst);
int					ft_cmdlst_len(t_cmd **lst);
t_string			get_var(t_string s);
int					matrix_len(t_string *s);
int					ft_cmdsize(t_cmd *cmd);
void				ft_fd_del(t_fd **fd);
void				ft_fdadd_back(t_fd **lst, t_fd *n);
t_fd				*ft_fd_new(char *name, int fd, t_type type);
bool				change_fd(t_cmd **cmd);

#endif
