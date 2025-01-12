/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:32:30 by malourei          #+#    #+#             */
/*   Updated: 2024/12/12 20:35:04 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_split
{
	char	**strs;
	int		i;
}			t_split;

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strrchr(char *s, char c);
size_t		ft_strlen(char *str);
int			ft_strcmp(char *c, char *d);
char		*ft_strdup(char *s);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_isalpha(int c);
int			ft_islower(int c);
int			ft_isupper(int c);
char		**join_matrix(char **m1, char **m2);

#endif
