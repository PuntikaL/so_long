/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:31:27 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/13 10:46:25 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int a)
{
	write (1, &a, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (str == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len ++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}
