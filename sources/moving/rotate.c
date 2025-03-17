/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:02:47 by luifer            #+#    #+#             */
/*   Updated: 2024/10/14 12:23:46 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//Function to apply the rotation formula
void	ft_rotate(double *x, double *y, double speedrot)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos(speedrot) - *y * sin(speedrot);
	*y = old_x * sin(speedrot) + *y * cos(speedrot);
}

//Function to rotate the player direction vector
//the direction vector (dir_x, dir_y) is rotated by the angle speedrot
//the new values for dir_x an dir_y are calculated using 2D rotation formulas
//it also rotate the camera plane (plane_x, plane_y) by the angle speedrot
//using the same rotation formula
int	ft_rotate_player_dir_vector(t_data *data, double speedrot)
{
	t_player	*ply;

	ply = &data->player;
	ft_rotate(&ply->dir_x, &ply->dir_y, speedrot);
	ft_rotate(&ply->plane_x, &ply->plane_y, speedrot);
	return (EXIT_FAILURE);
}

//Function to execute the rotation of the player in engine
int	ft_execute_rotation(t_data *data, double dirrot)
{
	int		move;
	double	speed_rotation;

	move = 0;
	speed_rotation = ROTATIONSPEED * dirrot;
	move += ft_rotate_player_dir_vector(data, speed_rotation);
	return (move);
}
