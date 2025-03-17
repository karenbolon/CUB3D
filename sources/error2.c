/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:47:17 by kbolon            #+#    #+#             */
/*   Updated: 2024/10/21 15:32:22 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	error_malloc(char *s)
{
	ft_putstr_fd(s, 2);
	exit (EXIT_FAILURE);
	return (0);
}

void	error_text_with_array(char *str, t_textinfo *text, char **arr)
{
	free_memory(arr);
	error_message_text(str, text);
}
