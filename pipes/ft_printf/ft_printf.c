/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:08:44 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 19:14:56 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit((long)(va_arg(args, int)), 10, 0);
	else if (specifier == 'u')
		count += ft_print_digit((long)(va_arg(args, unsigned int)), 10, 0);
	else if (specifier == 'x')
		count += ft_print_digit((long)(va_arg(args, unsigned int)), 16, 0);
	else if (specifier == 'X')
		count += ft_print_digit((long)(va_arg(args, unsigned int)), 16, 1);
	else if (specifier == '%')
		count += ft_print_char(specifier);
	else
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == ' ')
		{
			i++;
			while (format[i] == ' ' && format[i + 1] != '\0')
				i++;
			count += ft_printf_format(format[i], args);
		}
		else if (format[i] == '%' && format[i + 1] != '\0')
			count += ft_printf_format(format[++i], args);
		else
			count += ft_print_char(format[i]);
	}
	va_end(args);
	return (count);
}
