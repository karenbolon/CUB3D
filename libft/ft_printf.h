/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:33:33 by kbolon            #+#    #+#             */
/*   Updated: 2023/12/07 09:57:24 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

void	ft_putchar(int c, int *count);
void	ft_putnbr(unsigned long nu, int *count);
void	ft_putunbr(unsigned int n, int *count);
void	ft_hexaconv(unsigned long n, char format, int *count);
int		get_hex_digit(unsigned long num, char format);
int		ft_ptrconv(void *ptr, int *count);
void	ft_integer(char *format, va_list ap, int *count);
void	ft_sort(char c, va_list ap, int *count);
void	ft_putstr_printf(char *str, int *count);
int		ft_printf(const char *format, ...);

#endif
