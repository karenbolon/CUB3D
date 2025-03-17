/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:59:37 by kbolon            #+#    #+#             */
/*   Updated: 2023/05/24 17:00:36 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (size != 0)
	{
		while ((src[i] != '\0') && (i < size - 1))
		{
			dst[i] = src [i];
			i++;
		}
		if (size > 0)
			dst[i] = '\0';
	}
	return (j);
}
