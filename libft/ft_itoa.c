/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:29:48 by kbolon            #+#    #+#             */
/*   Updated: 2024/05/17 14:38:18 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char	*ft_convert_to_string(unsigned int nbr, int len, int sign)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (0);
	p[len--] = '\0';
	while (len >= 0)
	{
		p[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	if (sign == 1)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*p;

	sign = 0;
	len = ft_nbrlen(n);
	if (n == INT_MIN)
	{
		nbr = (unsigned int)(INT_MAX) + 1;
		sign = 1;
	}
	if (n < 0)
	{
		sign = 1;
		nbr = -n;
	}
	else
		nbr = n;
	p = ft_convert_to_string(nbr, len, sign);
	return (p);
}
