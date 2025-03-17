/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:08:50 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/21 14:29:19 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//initialize minimap struct
void	ft_initialize_minimap(t_data *data)
{
	data->minimap.tile_size = 10;
	data->minimap.width = data->mapinfo->map_width * data->minimap.tile_size;
	data->minimap.height = data->mapinfo->map_height * data->minimap.tile_size;
	data->minimap.mini_x = 10;
	data->minimap.mini_y = data->height - data->minimap.height - 10;
}

void	render_minimap(t_data *data)
{
	int		x;
	int		y;
	t_img	image;

	ft_initialize_minimap(data);
	image.img = mlx_new_image(data->mlx_conn, \
		data->minimap.width, data->minimap.height);
	image.img_addr = (int *)mlx_get_data_addr(image.img, \
		&image.bpp, &image.line_len, &image.endian);
	y = 0;
	while (y < (int)data->mapinfo->map_height)
	{
		x = 0;
		while (x < (int)data->mapinfo->map_width)
		{
			ft_make_mini_tiles(data, &image, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_conn, data->mlx_window, image.img,
		data->minimap.mini_x, data->minimap.mini_y);
	mlx_destroy_image(data->mlx_conn, image.img);
}
