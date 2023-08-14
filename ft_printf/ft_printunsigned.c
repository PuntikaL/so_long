/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:49:20 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/13 10:47:46 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = numlen(n);
	num = (char *)malloc(sizeof(char) * (len));
	if (!num)
		return (0);
	while (n != 0)
	{
		num [len - 1] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	return (num);
}

int	print_unsigned_int(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		length += ft_putchar('0');
	else
	{
		num = ft_utoa(n);
		length += ft_printstr(num);
		free(num);
	}
	return (length);
}
