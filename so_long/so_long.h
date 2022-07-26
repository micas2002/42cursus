/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/07/26 17:27:51 by miguel           ###   ########.fr       */
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
    int p_pos_x;
    int p_pos_y;
    int exit;
    int collectible;
    int true_false;
    t_vector size;
}t_map_info;

typedef enum s_type
{
    FLOOR = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}t_type;

typedef struct s_tile
{
    t_vector    pos;
    t_type    tile_type;
}t_tile;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*window;
    t_map_info  map_info;
	t_vector	window_size;
    t_vector    img_size;
    t_player    player_img;
    t_wall      wall_img;
    t_exit      exit_img;
    t_floor     floor_img;
    t_col       col_img;
    char       **map_tiles;
    t_tile     **map;
}t_game;

// INIT_GAME
int    init_game(t_game mlx);
void    open_imgs(t_game *mlx);

// VARS_UTILS
int		keys(int key_code);
int		close_window(void);

// MAP_UTILS
int		check_map(int fd, t_game *mlx);

// PLAYER_UTILS
int		player_movements(int key_code);

// RENDER
void    put_tiles(t_game mlx);

// TILEMAP
t_tile    **generate_tilemap(t_game *mlx);

#endif