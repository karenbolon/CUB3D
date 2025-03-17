/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:34:42 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/28 16:53:41 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//function initializes the text struct and saves it in our data struct
t_textinfo	*ft_initialize_info(char **arr)
{
	char		**grid;
	t_textinfo	*text;

	grid = read_map(*arr);
	if (!grid)
		error_message("ERROR: problem reading map\n");
	text = (t_textinfo *) ft_calloc (1, sizeof(t_textinfo));
	if (!text)
		error_message_simple("ERROR: calloc fail in text_init\n", grid);
	if (fill_paths(text, grid) == EXIT_FAILURE)
	{
		free(text);
		return (error_message("ERROR: calloc fail with paths\n"), NULL);
	}
	text->ceiling_rgb = populate_rgb_values(text, grid, 'C', \
		&text->hex_ceiling);
	if (!text->ceiling_rgb)
		error_text_with_array("ERROR: problems with rgb ceiling\n", text, grid);
	text->floor_rgb = populate_rgb_values(text, grid, 'F', &text->hex_floor);
	if (!text->floor_rgb)
		error_text_with_array("ERROR: problems with rgb floor\n", text, grid);
	text->size = PIXELS;
	if (filter_grid_lines(text, grid) == EXIT_FAILURE)
		return (NULL);
	return (text);
}

//function creates the path array needed to store our wall paths.  We need it
//in an char array to help load the textures in a while loop later
int	fill_paths(t_textinfo *text, char **grid)
{
	text->paths = (char **) ft_calloc(5, sizeof(char *));
	if (!text->paths)
		return (EXIT_FAILURE);
	text->paths[0] = find_cardinal_paths(grid, "NO");
	if (!text->paths[0])
		return (free(text->paths), EXIT_FAILURE);
	text->paths[1] = find_cardinal_paths(grid, "EA");
	if (!text->paths[1])
		return (free_partials((void **)text->paths), EXIT_FAILURE);
	text->paths[2] = find_cardinal_paths(grid, "SO");
	if (!text->paths[2])
		return (free_partials((void **)text->paths), EXIT_FAILURE);
	text->paths[3] = find_cardinal_paths(grid, "WE");
	if (!text->paths[3])
		return (free_partials((void **)text->paths), EXIT_FAILURE);
	text->paths[4] = NULL;
	return (EXIT_SUCCESS);
}

/*this function splits the rgb values for the floor and ceiling
checks the rgb value is within expectations, converts it to an int and
saves as an int array and converts it to a hex value*/
int	*validate_and_convert(t_textinfo *text, char **arr, \
		char **grid, unsigned long *hex_value)
{
	int		*rgb;
	int		i;

	i = -1;
	rgb = ft_calloc(3, sizeof(int));
	if (!rgb)
	{
		free_memory(arr);
		free_memory(grid);
		error_message_text("ERROR: problem with allocating rgb", text);
	}
	while (++i < 3)
	{
		rgb[i] = ft_atoi(arr[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free(rgb);
			free_memory(arr);
			free_memory(grid);
			error_message_text("ERROR: rgb is not valid\n", text);
		}
	}
	*hex_value = ((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + \
		(rgb[2] & 0xff);
	return (rgb);
}

/*funcion finds the rgb values in the .cub file, makes a char array and 
check for illegal characters too (empty or letters etc) and converts rgb 
values to hex.*/
int	*populate_rgb_values(t_textinfo *text, char **grid, int c, 
	unsigned long *hex_value)
{
	char	*temp;
	char	**arr;
	int		*rgb;

	temp = find_floor_ceiling(text, grid, c);
	if (!temp || !*temp)
	{
		free_memory(grid);
		free(temp);
		error_message_text("ERROR: floor/ceiling values not found\n", text);
	}
	arr = split_rgb_and_validate(grid, text, temp);
	if (!arr)
		error_message_text("ERROR: problem with splitting RGB\n", text);
	rgb = validate_and_convert(text, arr, grid, hex_value);
	free_memory(arr);
	return (rgb);
}

/*function checks if less than 3 values are provided, if
a character is not a digit etc*/
int	check_rgb_for_illegal_chars(char **arr)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = row_count(arr);
	if (count < 3 || count > 3)
		return (EXIT_FAILURE);
	while (++i < count)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (ft_isdigit(arr[i][j]))
				j++;
			else
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
