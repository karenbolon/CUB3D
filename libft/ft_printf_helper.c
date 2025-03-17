/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:32:33 by kbolon            #+#    #+#             */
/*   Updated: 2023/06/15 14:42:01 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *count)
{
	write (1, &c, 1);
	(*count)++;
}

void	ft_putnbr(unsigned long nu, int *count)
{
	long int	n;

	n = nu;
	if (n < 0)
	{
		ft_putchar('-', count);
		n *= -1;
	}
	if (n < 10)
		ft_putchar(n + '0', count);
	else
	{
		ft_putnbr(n / 10, count);
		ft_putchar(n % 10 + '0', count);
	}
}

void	ft_putunbr(unsigned int n, int *count)
{
	if (n < 10)
		ft_putchar(n + '0', count);
	else
	{
		ft_putnbr(n / 10, count);
		ft_putchar(n % 10 + '0', count);
	}
}

int	ft_ptrconv(void *ptr, int *count)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	if (n == 0)
	{
		write (1, "(nil)", 5);
		(*count) += 5;
	}
	else
	{
		write (1, "0x", 2);
		(*count) += 2;
		ft_hexaconv(n, 'x', count);
	}
	return (0);
}
