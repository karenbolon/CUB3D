/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:02:55 by kbolon            #+#    #+#             */
/*   Updated: 2023/05/11 16:04:42 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	val;
	size_t			i;

	p = b;
	val = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		*(unsigned char *) p = val;
		p++;
		i++;
	}
	return (b);
}
