/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:27:05 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/28 16:53:50 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	copy_valid_lines(char *grid, char *trimmed, char **arr)
{
	grid = ft_strdup(trimmed);
	if (!grid)
		error_message_simple("ERROR: mem alloc failed\n", arr);
}

void	check_empty_lines(char **grid, int i)
{
	if (i == 0)
		error_message_simple("ERROR: Grid is empty after \
			removing empty lines\n", grid);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc (sizeof(char) * (n + 1));
	if (p == 0)
		return (0);
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	print_map(char **arr)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = row_count(arr);
	while (i < count)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

//this function has been tailored for cub3d
int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (0);
	while ((str[i] != '\0') && (to_find[j] != '\0'))
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (1);
		i++;
		j = 0;
	}
	return (0);
}
