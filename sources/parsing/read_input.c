/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:14:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/21 12:21:05 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_extension(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len < 4 || ft_strncmp(&s[len - 4], ".cub", len - 4) != 0)
		error_message("ERROR: please include a .cub file\n");
}

size_t	row_count(char **grid)
{
	size_t	i;

	i = 0;
	if (!grid)
		return (0);
	while (grid[i])
		i++;
	return (i);
}

/*This function reads the .cub file.
The number of characters read per line impacts the game's resolution.
Based on a 1920x1080 resolution with 64x64 pixel tiles, the game can display
30 tiles horizontally (1920/64) and 16 tiles vertically (1080/64).*/
char	**read_map(char *s)
{
	int		fd;
	char	**arr;
	int		i;
	int		size;

	i = 0;
	size = 100;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		error_message("ERROR: unable to open file \n");
	arr = NULL;
	arr = (char **) malloc (sizeof(char *) * size); 
	if (!arr)
		error_reading_file("ERROR: problems mallocing\n", NULL, fd);
	arr = graphic_gnl(size, fd, arr, i);
	close(fd);
	if (!arr)
		return (NULL);
	if (ft_empty_check(arr))
		return (NULL);
	return (arr);
}

char	*ft_replace(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			s[i] = '\0';
		i++;
	}
	return (s);
}

char	**graphic_gnl(int size, int fd, char **arr, int i)
{
	char	*test;

	while (1)
	{
		if (i >= size - 1)
		{
			size *= 2;
			arr = (char **) malloc (sizeof(char *) * size);
			if (!arr)
				return (NULL);
		}
		test = get_next_line(fd);
		if (test == NULL)
			break ;
		arr[i] = ft_strdup(test);
		ft_replace(arr[i]);
		free(test);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
