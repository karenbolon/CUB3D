/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:03:01 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/14 12:25:42 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_calculate_texture_coordinates(t_data *data, t_ray *ray)
{
	data->textinfo->x = (int)(ray->wall_x * data->textinfo->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		data->textinfo->x = data->textinfo->size - data->textinfo->x - 1;
	data->textinfo->step = 1.0 * data->textinfo->size / ray->line_height;
	data->textinfo->pos = (ray->draw_start - data->height / 2 + \
		ray->line_height / 2) * data->textinfo->step;
}

//Function to update the texture pixels on the screen for render
//it calculates which part of the texture to apply to the current vertical line
//it flip the textures based on the direction the ray hits the wall
void	ft_update_texture_pixels(t_data *data, t_ray *ray, int x)
{
	int		y;
	int		colour;

	ft_get_texture_idx(data, ray);
	ft_calculate_texture_coordinates(data, ray);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		if (data->textinfo->idx >= NUM_TEXTURES || data->textinfo->x >= \
			data->textinfo->size || data->textinfo->y >= data->textinfo->size)
			return ;
		data->textinfo->y = (int)data->textinfo->pos % data->textinfo->size;
		data->textinfo->pos += data->textinfo->step;
		colour = data->textures[data->textinfo->idx][data->textinfo->size * \
			data->textinfo->y + data->textinfo->x];
		if (data->textinfo->idx == N || data->textinfo->idx == E)
			colour = (colour >> 1);
		if (colour > 0)
			data->texture_pixels[y][x] = colour;
		y++;
	}
}
