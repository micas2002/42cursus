/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/02 12:25:11 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "printf/ft_printf.h"

// PROTOTYPES

typedef struct s_img
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
}t_vars;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		close_window(int key_code, t_vars *vars);

#endif