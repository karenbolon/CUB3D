/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:51:39 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/28 17:21:13 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*this fcn takes what is read by get_next_line & looks for
specific items and paths such as NO, SO, WE, EA & returns
an array with only*/
char	*find_cardinal_paths(char **arr, char *s)
{
	char	*path_found;
	char	*path_extension;

	path_extension = NULL;
	path_found = find_string_path(arr, s);
	if (!path_found)
	{
		free_memory(arr);
		return (NULL);
	}
	path_extension = path_extractor(arr, path_found);
	if (!path_extension)
	{
		free(path_found);
		return (NULL);
	}
	return (path_extension);
}

char	*find_string_path(char **arr, char *s)
{
	int		i;
	int		count;
	char	*path_found;

	i = -1;
	count = row_count(arr);
	path_found = NULL;
	while (++i < count)
	{
		if (!ft_strncmp(arr[i], s, 2))
		{
			path_found = ft_strdup(arr[i] + 2);
			if (!path_found)
			{
				error_message_simple("ERROR: Memory Alloc failed\n", arr);
				return (NULL);
			}
			return (path_found);
		}
	}
	return (NULL);
}

/*this fcn looks moves past empty space and copies the line using
ft_strdup and returns the line*/
char	*path_extractor(char **arr, char *str)
{
	char	*path;
	int		i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	path = ft_strdup(&str[i]);
	if (!path)
	{
		free (str);
		error_message_simple("ERROR: Memory Alloc failed\n", arr);
		return (NULL);
	}
	free (str);
	return (path);
}

/*funciton looks for floor and ceiling values provided in .cub file*/
char	*find_floor_ceiling(t_textinfo *text, char **arr, int c)
{
	char	*path;

	path = find_path_in_info(arr, c);
	if (!path)
	{
		free_memory(arr);
		error_message_text("ERROR: mem alloc failed\n", text);
		return (NULL);
	}
	return (path);
}

/*function removes lines above and lines below the grid*/
char	**remove_empty_lines(char **arr)
{
	int		i;
	int		j;
	char	**updated_grid;
	char	*trimmed;

	j = 0;
	i = row_count(arr);
	updated_grid = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!updated_grid)
		error_message_simple("ERROR: Memory alloc failed with trimming\n", arr);
	i = 0;
	while (arr[i] != NULL)
	{
		trimmed = ft_trim_line(arr[i]);
		if (*trimmed != '\0')
		{
			copy_valid_lines(updated_grid[j], trimmed, arr);
			j++;
		}
		free(trimmed);
		i++;
	}
	check_empty_lines(updated_grid, j);
	free_memory(arr);
	return (updated_grid);
}
