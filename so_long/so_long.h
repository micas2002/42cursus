/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/15 10:14:08 by mibernar         ###   ########.fr       */
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

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	int		x;
	int		y;
}t_vars;

typedef struct s_img
{
	void	*reference;
	t_vars	size;
	char	*address;
	void	*pointer;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_img;


// IMG_UTILS
void	close_game(void *mlx_win);
int		close_window(void);

// VARS_UTILS
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_img	new_img(void *mlx, int width, int height);
t_img	new_sprite(void *mlx, char *path);

#endif