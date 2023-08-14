/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:48:04 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/13 10:42:29 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptrlen(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_printptr(uintptr_t n)
{	
	unsigned long	dec;

	if (n == 0)
		return (ft_putchar('0'));
	dec = (unsigned long)n;
	if (dec > 15)
	{
		ft_printptr(dec / 16);
		write (1, &"0123456789abcdef"[dec % 16], 1);
	}
	else
		write (1, &"0123456789abcdef"[dec], 1);
	return (hexlen(dec));
}

int	ft_printpointer(unsigned long long p)
{
	int	length;

	length = 2;
	ft_printstr("0x");
	if (p == 0)
		length += write(1, "0", 1);
	else
	{
		ft_printptr(p);
		length += ptrlen(p);
	}
	return (length);
}
