/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:30:58 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/14 12:05:12 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_partials((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(HEIGHT + 1, sizeof(int *));
	if (!data->texture_pixels)
		error_exit("ERROR: calloc init texture pixels total\n", data, NULL);
	i = 0;
	while (i < HEIGHT)
	{
		data->texture_pixels[i] = ft_calloc(WIDTH + 1, sizeof(int));
		if (!data->texture_pixels[i])
			error_exit("ERROR: calloc init texture pixels\n", data, NULL);
		i++;
	}
}

//Function to get the texture index from the texture info struct
//if side is not zero, we're working on the y axis, else on the x
//if dir_y is greather than zero then we're on South 
//else North. If x axis is lower than zero is west else east
void	ft_get_texture_idx(t_data *data, t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->dir_y > 0)
			data->textinfo->idx = S;
		else
			data->textinfo->idx = N;
	}
	else
	{
		if (ray->dir_x < 0)
			data->textinfo->idx = W;
		else
			data->textinfo->idx = E;
	}
}

int	*xpm_buffer_image(t_data *data, char *path)
{
	t_img	temp;
	int		*buff;
	int		x;
	int		y;

	ft_init_texture_img(data, &temp, path);
	buff = (int *)ft_calloc(pow(data->textinfo->size, 2), sizeof(int));
	if (!buff)
		error_malloc("ERROR: Unable to calloc buffer\n");
	y = 0;
	while (y < data->textinfo->size)
	{
		x = 0;
		while (x < data->textinfo->size)
		{
			buff[y * data->textinfo->size + x] = temp.img_addr[y * \
				data->textinfo->size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_conn, temp.img);
	return (buff);
}

//Function to initialize the image, it creates the new image using 
//the mlx library and checks it was correctly created and saves the 
//image address
int	ft_initialize_textures(t_data *data)
{
	int		i;

	i = 0;
	data->textures = ft_calloc(5, sizeof(int **));
	if (!data->textures)
		return (EXIT_FAILURE);
	while (i < 4)
	{
		data->textures[i] = xpm_buffer_image(data, data->textinfo->paths[i]);
		if (!data->textures[i])
		{
			return (error_message_simple("Error loading textures in \
				ft_initialize_textures\n", NULL));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_put_pixel_to_img(t_img *imginfo, int x, int y, int colour)
{
	int	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = (int *)((char *)imginfo->img_addr + (y * imginfo->line_len) \
		+ (x * (imginfo->bpp / 8)));
	*pixel = colour;
}
