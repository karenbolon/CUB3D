/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:30 by kbolon            #+#    #+#             */
/*   Updated: 2023/05/24 15:43:44 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*src_char;
	char	*dest_char;

	src_char = (char *)src;
	dest_char = (char *)dest;
	if (!dest_char && !src_char)
		return (0);
	if (dest_char != src_char || n != 0)
	{
		while (n-- > 0)
			*dest_char++ = *src_char++;
	}
	return (dest);
}
