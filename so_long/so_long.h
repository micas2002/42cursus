/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/07/13 12:46:45 by miguel           ###   ########.fr       */
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

# define WIN_WIDTH 975
# define WIN_HEIGHT 375
# define PATH "/home/miguel/projects/42cursus/so_long/map.ber"

// PROTOTYPES

typedef struct s_player
{
	void    *player_img;
}	t_player;

typedef struct s_wall
{
	void    *wall_img;
}	t_wall;

typedef struct s_exit
{
	void    *exit_img;
}	t_exit;

typedef struct s_floor
{
	void    *floor_img;
}	t_floor;

typedef struct s_col
{
	void    *col_img;
}	t_col;

typedef struct s_vector
{
	int	x;
	int	y;
}t_vector;

typedef struct s_map_info
{
    int player;
    int exit;
    int collectible;
    int true_false;
    t_vector size;
}t_map_info;

typedef struct s_tile
{
    t_vector    pos;
}t_tile;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*window;
	t_vector	window_size;
    t_vector    img_size;
    t_player    player_img;
    t_wall      wall_img;
    t_exit      exit_img;
    t_floor     floor_img;
    t_col       col_img;
    char       **map_tiles;
}t_game;

// INIT_GAME
int    init_game(t_game mlx);
void    open_imgs(t_game *mlx);

// VARS_UTILS
int		keys(int key_code);
int		close_window(void);

// MAP_UTILS
int		check_map(int fd);

// PLAYER_UTILS
int		player_movements(int key_code);

// RENDER
void    put_tiles(t_game mlx);

#endif