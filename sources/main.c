/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:41:29 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/21 13:33:01 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_args(t_textinfo *text)
{
	valid_chars(text);
	check_map_size(text);
	check_map_items(text);
	flood_fill(text);
}

int	main(int ac, char **av)
{
	t_textinfo	*text;
	t_data		*data;

	if (ac != 2)
		error_message("ERROR: include ./cub3D & .cub\n");
	data = NULL;
	check_extension(av[1]);
	text = ft_initialize_info(&av[1]);
	if (!text)
		error_message("ERROR: problem loading text");
	check_args(text);
	if (ft_initialize_data(&data, text) == EXIT_FAILURE)
		error_exit("ERROR: problem loading text", data, NULL);
	if (ft_initialize_connection(data) == EXIT_FAILURE)
		error_exit("ERROR: problem init connection", data, NULL);
	if (ft_initialize_textures(data) == EXIT_FAILURE)
		error_exit("ERROR: problem init textures", data, NULL);
	ft_init_game(data);
	ft_loop_events(data);
	ft_exit_game(data);
	return (EXIT_SUCCESS);
}
