/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:56:54 by luifer            #+#    #+#             */
/*   Updated: 2024/10/14 12:19:42 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//Function to check if the new position to move the player in the map
//is a valid one (it's a floor tile 0 or a door 4) in which case the movement
//will be marked as possible. The door is a bonus feature.
//it will return 0 when is a valid position, 0 otherwise
int	ft_check_if_empty(t_data *data, double x, double y)
{
	int	tile;

	if (!data || !data->mapinfo->map)
		return (EXIT_FAILURE);
	tile = data->mapinfo->map[(int)y][(int)x];
	if (tile == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

//Function to check if the new position is inside the bounds of the map
//it assures that the new player position stays inside the map limits 
//(height and width) in which case returns success status
int	ft_check_if_inside_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->mapinfo->map_width - 1.25)
		return (EXIT_FAILURE);
	if (y < 0.25 || y > data->mapinfo->map_height - 0.25)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//Function to check if there is no bonus flag: if not present it check that
//movement is inside the map limits. When bonus is present it also check
//for the chance to open doors
int	ft_allow_movement(t_data *data, double x, double y)
{
	if (BONUS)
	{
		if (ft_check_if_empty(data, x, y) == 0)
			return (EXIT_SUCCESS);
	}
	else
	{
		if (ft_check_if_inside_map(data, x, y) == 0)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

//Function to validate the movement of the player. It initializes move to 0
//it check if the position in x after movement is valid while keep the current
// y position the same. If is valid it will update the player x position. 
//it also check if the new y position is valid while keeping the current x 
//position, when is valid it will update the new y position of the player
int	ft_validate_movement(t_data *data, double x_after, double y_after)
{
	int	move;

	move = EXIT_SUCCESS;
	if (ft_allow_movement(data, x_after, data->player.pos_y))
	{
		data->player.pos_x = x_after;
		move = EXIT_FAILURE;
	}
	if (ft_allow_movement(data, data->player.pos_x, y_after))
	{
		data->player.pos_y = y_after;
		move = EXIT_FAILURE;
	}
	return (move);
}
