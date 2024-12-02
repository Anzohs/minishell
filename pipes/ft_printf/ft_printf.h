/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:41:54 by malourei          #+#    #+#             */
/*   Updated: 2024/04/26 00:41:54 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_digit(long nbr, int base, int upper);
int	ft_print_pointer(unsigned long int p);
int	ft_printf(const char *format, ...);

#endif
