/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:47:58 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/14 16:41:12 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	error_message(char *str)
{
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	error_reading_file(char *str, char **arr, int fd)
{
	if (fd)
		close (fd);
	if (arr)
		free_memory(arr);
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

int	error_message_simple(char *str, char **arr)
{
	if (arr)
		free_memory(arr);
	ft_putstr_fd(str, 2);
	return (EXIT_FAILURE);
}

void	error_message_text(char *str, t_textinfo *text)
{
	free_text(text);
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	error_exit(char *str, t_data *data, t_textinfo *text)
{
	if (data)
		ft_exit_game(data);
	if (text)
		free_text(text);
	if (data)
		ft_clean_exit(data);
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}
