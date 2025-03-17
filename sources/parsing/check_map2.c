/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:27:01 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/22 11:16:59 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	filter_grid_lines(t_textinfo *text, char **grid)
{
	int	start;

	start = find_grid_start(grid);
	if (check_after_grid(grid, start) == EXIT_FAILURE)
	{
		free_memory(grid);
		error_exit("ERROR: extra content found\n", NULL, text);
		return (EXIT_FAILURE);
	}
	text->grid = copy_grid(text, grid, start);
	if (!text->grid)
	{
		free_memory(grid);
		error_exit("ERROR: problems copying grid\n", NULL, text);
		return (EXIT_FAILURE);
	}
	free_memory(grid);
	return (EXIT_SUCCESS);
}

char	**copy_grid(t_textinfo *text, char **grid, int start)
{
	int		j;
	int		count;
	char	**temp;

	j = 0;
	count = row_count(grid);
	temp = (char **)malloc((count + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (grid[start] != NULL && (ft_strchr(grid[start], '1') || \
		ft_strchr(grid[start], '0') || ft_strchr(grid[start], ' ') || \
		ft_strchr(grid[start], '	') || ft_strchr(grid[start], '\t')))
	{
		temp[j] = ft_strdup(grid[start]);
		if (!temp[j])
		{
			free_memory(temp);
			free_memory(grid);
			error_exit("ERROR: problems copying grid\n", NULL, text);
		}
		j++;
		start++;
	}
	temp[j] = NULL;
	return (temp);
}

/*function looks for paths to textures or emptry lines and stops
when anything but the paths and leading empty lines are found
which would technically be the grid which is tested elsewhere*/
int	find_grid_start(char **grid)
{
	int		i;

	i = 0;
	while (ft_strstr(grid[i], "NO") || ft_strstr(grid[i], "SO") || \
		ft_strstr(grid[i], "WE") || ft_strstr(grid[i], "EA") || \
		ft_strstr(grid[i], "F") || ft_strstr(grid[i], "C") || \
		ft_strlen(grid[i]) == 0)
	{
		i++;
	}
	return (i);
}

//function checks for items after the grid and returns an error if anything
//is found
int	check_after_grid(char **grid, int start)
{
	int		i;

	i = start;
	while (grid[i] != NULL && (ft_strchr(grid[i], '1') || \
		ft_strchr(grid[i], '0')))
	{
		i++;
	}
	while (grid[i] != NULL)
	{
		if (ft_strlen(grid[i]) > 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_empty_check(char **arr)
{
	int	i;

	i = row_count(arr);
	if (i < 2)
	{
		free_memory(arr);
		free(arr);
		error_reading_file("ERROR: empty file\n", 0, 0);
		return (1);
	}
	return (0);
}
