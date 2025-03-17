/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:18:58 by kbolon            #+#    #+#             */
/*   Updated: 2023/12/07 13:02:41 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p;
	const unsigned char	*q;

	p = (const unsigned char *)s1;
	q = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*p == *q && n > 0)
	{
		p++;
		q++;
		n--;
		if (n == 0)
			return (0);
	}
	if (*p != *q)
		return (*p - *q);
	return (0);
}
