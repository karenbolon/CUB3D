/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:31:47 by kbolon            #+#    #+#             */
/*   Updated: 2023/11/15 13:36:20 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_digit(unsigned long num, char format)
{
	if (num < 10)
		return ('0' + num);
	else
	{
		if (format == 'X')
			return ('A' + num - 10);
		else if (format == 'x')
			return ('a' + num - 10);
	}
	return (0);
}

void	ft_hexaconv(unsigned long n, char format, int *count)
{
	int				i;
	char			hexadecimalnum[17];
	unsigned long	remainder;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	while (n != 0)
	{
		remainder = n % 16;
		hexadecimalnum[i++] = get_hex_digit(remainder, format);
		n = n / 16;
	}
	while (i > 0)
		ft_putchar(hexadecimalnum[--i], count);
}

void	ft_putstr_printf(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		(*count)++;
	}
}

void	ft_sort(char c, va_list ap, int *count)
{
	if (c == '%')
		ft_putchar('%', count);
	else if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (c == 's')
		ft_putstr_printf(va_arg(ap, char *), count);
	else if (c == 'u')
		ft_putunbr(va_arg(ap, unsigned long), count);
	else if (c == 'x' || c == 'X')
		ft_hexaconv(va_arg(ap, unsigned int), c, count);
	else if (c == 'p')
		ft_ptrconv(va_arg(ap, void *), count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			i;

	count = 0;
	i = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' \
			|| format[i + 1] == 'd' || format[i + 1] == 'i' || format[i + 1] == \
			'u' || format[i + 1] == 'x' || format[i + 1] == 'X' || \
			format[i + 1] == '%' || format[i + 1] == 'p'))
		{
			ft_sort(format[i + 1], ap, &count);
			i++;
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
