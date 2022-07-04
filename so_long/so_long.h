/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/07/04 16:14:35 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

# define WIN_WIDTH 600
# define WIN_HEIGHT 600

// PROTOTYPES
typedef struct s_bgd
{
	void	*ptr;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
}t_bgd;

typedef struct s_player_img
{
	void	*ptr;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
}t_player_img;

typedef struct s_map
{
	int	with;
	int	heigth;
}t_map;

typedef struct s_mlx
{
	void			*ptr;
	void			*window;
	t_map			map;
	t_player_img	plr_img;
	t_bgd			bgd;
	int				x;
	int				y;
}t_mlx;

// VARS_UTILS
int		keys(int key_code);
int		close_window(void);

// IMG_UTILS
//void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	new_sprite(t_mlx mlx, char *path, int x, int y);

// MAP_UTILS
int		check_map(int fd);

// PLAYER_UTILS
int		player_movements(int key_code);

#endif