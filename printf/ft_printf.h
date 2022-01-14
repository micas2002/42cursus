/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:04:18 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/14 15:47:53 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

// PROTOTYPES

int	ft_printf(const char *format, ...);
int	ft_printf_c(va_list args);
int	ft_printf_i(va_list args);
int	ft_printf_d(va_list args);
int	ft_printf_p(va_list args);
int	ft_printf_percent(va_list args);
int	ft_printf_s(va_list args);
int	ft_printf_u(va_list args);
int	ft_printf_x_lower(va_list args);
int	ft_printf_x_upper(va_list args);

#endif
