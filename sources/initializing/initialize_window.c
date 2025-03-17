/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:52:09 by luifer            #+#    #+#             */
/*   Updated: 2024/10/20 08:14:56 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//Function to create a connection with the library and creates a window
//into that connection. It also checks that connection and window
//were created without problems
int	ft_initialize_connection(t_data *data)
{
	data->mlx_conn = mlx_init();
	if (!data->mlx_conn)
	{
		ft_putstr_fd("ERROR: problems with mlx_init\n", 2);
		return (EXIT_FAILURE);
	}
	data->mlx_window = mlx_new_window(data->mlx_conn, WIDTH, HEIGHT, "Cub3D");
	if (!data->mlx_window)
	{
		mlx_destroy_display(data->mlx_conn);
		free(data->mlx_conn);
		ft_putstr_fd("ERROR: problems with mlx window\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//ft_memset clears the pointers in image to NULL/0 while maintaining
//the allocated memory
int	ft_init_texture_img(t_data *data, t_img *image, char *path)
{
	ft_memset(image, 0, sizeof(t_img));
	image->img = mlx_xpm_file_to_image(data->mlx_conn, path, \
		&image->texture_width, &image->texture_height);
	if (!image->img)
	{
		error_message("ERROR: Unable to load texture image\n");
		return (EXIT_FAILURE);
	}
	image->img_addr = (int *)mlx_get_data_addr(image->img, \
		&image->bpp, &image->line_len, &image->endian);
	if (!image->img_addr)
	{
		error_message("ERROR: Unable to load texture address\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//ft_memset clears the pointers in image to NULL/0 while maintaining
//the allocated memory
int	ft_init_img(t_data *data, t_img *image)
{
	ft_memset(image, 0, sizeof(t_img));
	image->img = mlx_new_image(data->mlx_conn, WIDTH, HEIGHT);
	if (!image->img)
	{
		error_message("ERROR: Unable to load image\n");
		return (EXIT_FAILURE);
	}
	image->img_addr = (int *)mlx_get_data_addr(image->img, \
		&image->bpp, &image->line_len, &image->endian);
	if (!image->img_addr)
	{
		error_message("ERROR: Unable to load image address\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
