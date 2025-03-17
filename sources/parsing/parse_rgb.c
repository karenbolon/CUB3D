/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:00:21 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/28 17:21:03 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//splits the rgb using ft_split and checks for illegal values
char	**split_rgb_and_validate(char **grid, t_textinfo *text, char *temp)
{
	char	**arr;

	arr = ft_split(temp, ',');
	free(temp);
	if (!arr)
	{
		free_memory(grid);
		error_message_text("ERROR: problem with splitting RGB\n", text);
	}
	if (check_rgb_for_illegal_chars(arr) == EXIT_FAILURE)
	{
		free_memory(grid);
		free_memory(arr);
		error_message_text("ERROR: invalid chars in RGB\n", text);
	}
	return (arr);
}

/*funciton looks for floor and ceiling values provided in .cub file*/
char	*find_path_in_info(char **arr, int c)
{
	int		i;
	int		count;
	char	*path;

	i = -1;
	count = row_count(arr);
	while (++i < count)
	{
		path = ft_strchr(arr[i], c);
		if (path)
		{
			while (*path && !ft_isdigit(*path))
				path++;
			if (path)
			{
				return (ft_strdup(path));
			}
		}
	}
	return (NULL);
}
