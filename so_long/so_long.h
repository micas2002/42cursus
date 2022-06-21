/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/21 16:08:33 by miguel           ###   ########.fr       */
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
# include <math.h>
# include <X11/keysym.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

# define WIN_WIDTH 900
# define WIN_HEIGHT 900

// PROTOTYPES

typedef struct s_player
{
	
}	t_player;

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

// IMG_UTILS
int		close_game(int key_code);
int		close_window(void);

// VARS_UTILS
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_img	new_img(void *mlx, int width, int height);
t_img	new_sprite(void *mlx);

// MAP_UTILS
int	check_map(int fd);

#endif