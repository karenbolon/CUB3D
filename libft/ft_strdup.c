/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:42:25 by kbolon            #+#    #+#             */
/*   Updated: 2023/12/07 09:41:28 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	p = (char *)malloc (sizeof(char) * (j + 1));
	if (p == 0)
		return (0);
	while (i < j)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
