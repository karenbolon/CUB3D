/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:52:48 by kbolon            #+#    #+#             */
/*   Updated: 2023/05/22 15:16:08 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		val;
	size_t				i;

	val = (unsigned char) c;
	p = s;
	i = 0;
	while (i < n)
	{
		if (*p == val)
			return ((void *)p);
		i++;
		p++;
	}
	return (0);
}
