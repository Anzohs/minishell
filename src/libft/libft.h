/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:32:30 by malourei          #+#    #+#             */
/*   Updated: 2024/11/25 22:15:11 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strrchr(char *s, char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *c, char *d);
char	*ft_strdup(char *s);

#endif
