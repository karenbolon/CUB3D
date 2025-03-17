/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:59:22 by luifer            #+#    #+#             */
/*   Updated: 2024/10/14 12:25:02 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//Function to move the player forward, it will take 2 variables to update
//player x and y position after movement. It will add the x_dir to pos_x 
//to update new x position. It will add dir_y to pos_y to update new y position
//it will call the validate movement function to check if move is valid in 
//the map.
int	ft_move_player_fw(t_data *data)
{
	double	x_after;
	double	y_after;

	x_after = data->player.pos_x + data->player.dir_x * MOVEMENTSPEED;
	y_after = data->player.pos_y + data->player.dir_y * MOVEMENTSPEED;
	if (ft_validate_movement(data, x_after, y_after))
	{
		data->player.pos_x = x_after;
		data->player.pos_y = y_after;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//Function to move the player backward, it will take 2 variables to update
//player x and y position after movement. It will substract the x_dir from 
//pos_x to update new x position. It will substract dir_y from pos_y to 
//update new y position it will call the validate movement function to 
//check if move is valid in the map.
int	ft_move_player_bw(t_data *data)
{
	double	x_after;
	double	y_after;

	x_after = data->player.pos_x - data->player.dir_x * MOVEMENTSPEED;
	y_after = data->player.pos_y - data->player.dir_y * MOVEMENTSPEED;
	if (ft_validate_movement(data, x_after, y_after))
	{
		data->player.pos_x = x_after;
		data->player.pos_y = y_after;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//Function to move the player to the left, it will take 2 variables to update
//player x and y position after movement. It will add the y_dir to pos_x 
//to update new x position. It will substract dir_y from pos_y to update 
//new y position it will call the validate movement function to check if 
//move is valid in the map.
int	ft_move_player_left(t_data *data)
{
	double	x_after;
	double	y_after;

	x_after = data->player.pos_x + data->player.dir_y * MOVEMENTSPEED;
	y_after = data->player.pos_y - data->player.dir_x * MOVEMENTSPEED;
	if (ft_validate_movement(data, x_after, y_after))
	{
		data->player.pos_x = x_after;
		data->player.pos_y = y_after;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//Function to move the player to the right, it will take 2 variables to update
//player x and y position after movement. It will substract the y_dir from 
//pos_x to update new x position. It will add dir_x to pos_x to update new y 
//position it will call the validate movement functionto check if move is 
//valid in the map.
int	ft_move_player_right(t_data *data)
{
	double	x_after;
	double	y_after;

	x_after = data->player.pos_x - data->player.dir_y * MOVEMENTSPEED;
	y_after = data->player.pos_y + data->player.dir_x * MOVEMENTSPEED;
	if (ft_validate_movement(data, x_after, y_after))
	{
		data->player.pos_x = x_after;
		data->player.pos_y = y_after;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//Function to move the player through the map world
//it will check if move_y is equal to 1 or -1 to determine
//if movement is backward or forward. it will check if move_x
//is 1 or -1 to check if movement is left or right. It will return
//the move number
int	ft_move_player(t_data *data)
{
	int	move;

	move = 0;
	if (data->player.move_y == 1)
		move += ft_move_player_fw(data);
	if (data->player.move_y == -1)
		move += ft_move_player_bw(data);
	if (data->player.move_x == -1)
		move += ft_move_player_left(data);
	if (data->player.move_x == 1)
		move += ft_move_player_right(data);
	if (data->player.rotate != 0)
		move += ft_execute_rotation(data, data->player.rotate);
	return (move);
}
