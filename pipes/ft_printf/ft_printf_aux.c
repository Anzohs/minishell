/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:24:16 by malourei          #+#    #+#             */
/*   Updated: 2024/09/15 21:53:54 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(2, &c, 1));
}

int	ft_print_str(char *s)
{
	int	i;

	if (!s)
		return (write(2, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		ft_print_char(s[i]);
		i++;
	}
	return (i);
}

int	ft_print_digit(long nbr, int base, int upper)
{
	int		count;
	char	*base_string;

	if (upper)
		base_string = "0123456789ABCDEF";
	else
		base_string = "0123456789abcdef";
	if (nbr < 0)
	{
		ft_print_char('-');
		nbr *= -1;
		return (ft_print_digit(nbr, base, upper) + 1);
	}
	else if (nbr < base)
		return (ft_print_char(base_string[nbr]));
	else
	{
		count = ft_print_digit(nbr / base, base, upper);
		return (count + ft_print_digit(nbr % base, base, upper));
	}
}

static int	ft_print_pointer_help(unsigned long int nbr)
{
	int		count;
	char	*base_string;

	count = 0;
	base_string = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_print_pointer_help(nbr / 16);
	count += ft_print_char(base_string[nbr % 16]);
	return (count);
}

int	ft_print_pointer(unsigned long int p)
{
	int	count;

	count = 0;
	if (!p)
		count += ft_print_str("(nil)");
	else
	{
		count += ft_print_str("0x");
		count += ft_print_pointer_help(p);
	}
	return (count);
}
