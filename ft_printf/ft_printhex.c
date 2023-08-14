/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:11:13 by pleepago          #+#    #+#             */
/*   Updated: 2023/08/14 17:16:29 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned	int num)
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

int	ft_printhex_up(unsigned int n)
{
	unsigned long	dec;

	if (n == 0)
		return (ft_putchar('0'));
	dec = (unsigned long)n;
	if (dec > 15)
	{
		ft_printhex_up(dec / 16);
		write (1, &"0123456789ABCDEF"[dec % 16], 1);
	}
	else
		write (1, &"0123456789ABCDEF"[dec], 1);
	return (hexlen(dec));
}

int	ft_printhex_low(unsigned int n)
{
	unsigned long	dec;

	if (n == 0)
		return (ft_putchar('0'));
	dec = (unsigned long)n;
	if (dec > 15)
	{
		ft_printhex_low(dec / 16);
		write (1, &"0123456789abcdef"[dec % 16], 1);
	}
	else
		write (1, &"0123456789abcdef"[dec], 1);
	return (hexlen(dec));
}
