/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:33:52 by kbolon            #+#    #+#             */
/*   Updated: 2023/05/22 15:16:49 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_release(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	ft_count_words(const char *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == charset || str[i + 1] == '\0') == 1
			&& (str[i] == charset || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	ft_write_word(char *dest, const char *from, char charset)
{
	int	i;

	i = 0;
	while ((from[i] == charset || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_write_split(char **split, const char *str, char charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == charset || str[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (str[i + j] != charset && str[i + j] != '\0')
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == 0)
				return (ft_release(split, word - 1));
			ft_write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;

	words = ft_count_words(str, c);
	res = (char **) malloc (sizeof(char *) * (words + 1));
	if (res == 0)
		return (0);
	res[words] = 0;
	if (ft_write_split(res, str, c) == -1)
		return (0);
	return (res);
}
