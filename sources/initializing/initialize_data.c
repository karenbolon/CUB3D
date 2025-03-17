/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:08:40 by luifer            #+#    #+#             */
/*   Updated: 2024/10/17 13:04:21 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//function initializes the map struct and saves it in our data struct
int	ft_initialize_map(t_data *data, t_textinfo *text)
{
	if (!data)
		return (error_message_simple("ERROR: data struct not init", NULL));
	data->mapinfo = (t_mapinfo *)ft_calloc(1, sizeof(t_mapinfo));
	if (!data->mapinfo)
		return (error_message_simple("ERROR: problems init map\n", NULL));
	data->mapinfo->map_height = row_count(text->grid);
	return (EXIT_SUCCESS);
}

//Function to initialize the data struct so we can run our game eventually
int	ft_initialize_data(t_data **data, t_textinfo *text)
{
	*data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!*data)
		return (error_message_simple("ERROR: problems copying grid\n", NULL));
	(*data)->textinfo = text;
	if (ft_initialize_map(*data, text) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_make_game_map(*data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_initialize_player(*data) == EXIT_FAILURE)
		return (error_message_simple("ERROR: problems init player\n", NULL));
	return (EXIT_SUCCESS);
}

//Function to initialize the player structure
int	ft_initialize_player(t_data *data)
{
	int	x;
	int	y;

	ft_memset(&data->player, 0, sizeof(t_player));
	find_player_direction(data);
	x = find_item(data->mapinfo->map, 'x');
	y = find_item(data->mapinfo->map, 'y');
	data->player.pos_x = x + 0.5;
	data->player.pos_y = y + 0.5;
	data->height = HEIGHT;
	data->width = WIDTH;
	data->mapinfo->map[y][x] = '0';
	if (check_player_position(data) == EXIT_FAILURE)
		return (error_message_simple("ERROR: problems player position\n", NULL));
	ft_init_player_dir(data);
	return (EXIT_SUCCESS);
}

//function check that the player position is legit
int	check_player_position(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	count = 0;
	if (data->mapinfo->map[i][j - 1] == '1')
		count++;
	if (data->mapinfo->map[i][j + 1] == '1')
		count++;
	if (data->mapinfo->map[i - 1][j] == '1')
		count++;
	if (data->mapinfo->map[i - 1][j] == '1')
		count++;
	if (count == 4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	find_player_direction(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->mapinfo->map[y])
	{
		x = 0;
		while (data->mapinfo->map[y][x])
		{
			if (ft_strchr("NESW", data->mapinfo->map[y][x]) \
				&& data->player.direction == '\0')
				data->player.direction = data->mapinfo->map[y][x];
			x++;
		}
		y++;
	}
}
