/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:52:43 by malourei          #+#    #+#             */
/*   Updated: 2025/03/05 21:34:25 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "pipex.h"
#include "../signals/ft_signals.h"
#include <fcntl.h>

extern int g_sig;

static char	*generate_random_filename(void)
{
	static t_string	charset;
	char			*filename;
	int				i;
	int				len;

	charset = FL;
	srand(time(NULL));
	len = 11;
	filename = ft_calloc(len + 9, 1);
	if (!filename)
		return (NULL);
	ft_strcpy(filename, "/tmp/.");
	i = 4;
	while (++i < len)
		filename[i] = charset[rand() % (ft_strlen(charset) - 1)];
	return (filename);
}

static void	here_doc(t_fd **f, t_string filename, int f_d)
{
	char	*line;
	char	*limiter;

	if (f_d == -1)
		return ;
	limiter = ft_strdup((*f)->name);
	free((*f)->name);
	(*f)->name = ft_strdup(filename);
	(*f)->fd = f_d;
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 || g_sig)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, f_d);
		free(line);
	}
	free(limiter);
	return ;
}

static int	check_here_doc(t_fd *fd)
{
	t_fd		*tmp;
	t_string	filename;
	int			i;

	tmp = fd;
	i = 0;
	filename = generate_random_filename();
	if (!filename)
		return (-1);
	while (tmp && !g_sig)
	{
		if (tmp->type == HEREDOC)
		{
			i = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			here_doc(&tmp, filename, i);
			if (g_sig)
				break ;
		}
		tmp = tmp->next;
		if (i > 0)
			ft_close(i);
	}
	free(filename);
	return (i);
}

bool	check_per_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	mini()->sig = 2;
	load_signals();
	while (tmp)
	{
		if (tmp->read == 1000)
			tmp->read = check_here_doc(tmp->fd);
		if (g_sig || tmp->read == -1)
			break ;
		tmp = tmp->next;
	}
	mini()->sig = 1;
	load_signals();
	return (g_sig == 0);
}
