/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:33:48 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/13 10:54:16 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_printpointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += print_unsigned_int(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_printhex_low(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_printhex_up(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		args;
	int			print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += 1;
			print_length += get_format(args, str[i]);
		}
		else
			print_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
