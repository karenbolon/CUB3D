/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:42:05 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/14 20:22:12 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*function checks that there are only NSEW10 in the grid*/
void	valid_chars(t_textinfo *text)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (text->grid[i] != NULL)
	{
		j = 0;
		while (text->grid[i][j] != '\0')
		{
			if (ft_strchr("01NSEW \t\n", text->grid[i][j]))
				j++;
			else
				error_message_text("ERROR: illegal character in map\n", text);
		}
		i++;
	}
}

void	count_chars(char **arr, size_t *player)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == 'N' || arr[i][j] == 'S' || \
				arr[i][j] == 'W' || arr[i][j] == 'E')
				(*player) += 1;
			j++;
		}
		i++;
	}
}

/*function checks if only 1 player*/
void	check_map_items(t_textinfo *text)
{
	size_t		player;

	player = 0;
	count_chars(text->grid, &player);
	if (player > 1 || player < 1)
		error_message_text("ERROR: check content (map/players etc)\n", text);
}

/*trims the line found in the .cub file.  Ensures there are no leading or
trailing spaces*/
char	*ft_trim_line(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}
