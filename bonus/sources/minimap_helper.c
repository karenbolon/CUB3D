/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:19:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/21 15:37:26 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_find_colour(t_data *data, int y, int x)
{
	if (data->mapinfo->map[y][x] == '1')
		return (BLACK);
	else if (x == (int)data->player.pos_x && \
		y == (int)data->player.pos_y)
		return (RED);
	return (WHITE);
}

void	ft_make_mini_tiles(t_data *data, t_img *img, int y, int x)
{
	int	i;
	int	j;
	int	colour;

	i = 0;
	colour = ft_find_colour(data, y, x);
	while (i < data->minimap.tile_size)
	{
		j = 0;
		while (j < data->minimap.tile_size)
		{
			img->img_addr[(y * data->minimap.tile_size + j) * \
			data->minimap.width + (x * data->minimap.tile_size \
			+ i)] = colour;
			j++;
		}
		i++;
	}
}
