/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/16 14:43:22 by mibernar         ###   ########.fr       */
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
# include "printf/ft_printf.h"

// PROTOTYPES

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	t_img	img;
	int		x;
	int		y;
}t_mlx;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
}t_vars;

// IMG_UTILS
void	close_game(void *mlx_win);
int		close_window(void);

// VARS_UTILS
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_img	new_img(void *mlx, int width, int height);
t_img	new_sprite(void *mlx);

#endif