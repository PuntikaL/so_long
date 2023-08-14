/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:48:28 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/13 10:53:45 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		get_format(va_list args, const char format);
int		ft_putchar(int a);
int		ft_printstr(char *str);
int		ft_printhex_up(unsigned int dec);
int		ft_printhex_low(unsigned int dec);
int		ft_putnbr(int n);
char	numlen(unsigned int n);
char	*ft_utoa(unsigned int n);
int		print_unsigned_int(unsigned int n);
int		ft_printpointer(unsigned long long p);
int		hexlen(unsigned int num);
int		ft_nbrlen(long n);
int		ft_putnbr(int a);

#endif
