/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:21:35 by miguel            #+#    #+#             */
/*   Updated: 2022/07/26 17:25:32 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game mlx)
{
//    char    tile_type;
    int     x;
    int     y;
    
    x = mlx.map_info.p_pos_x;
    y = mlx.map_info.p_pos_y;
    mlx.map_tiles[x][y] = '0';
    mlx.map_tiles[x][y - 1] = 'P';
    return ;
}

void	move_down(t_game mlx)
{
    int     x;
    int     y;
    
    x = mlx.map_info.p_pos_x;
    y = mlx.map_info.p_pos_y;
    mlx.map[x][y] = '0';
    mlx.map[x][y + 1] = 'P';
    return ;
}

void	move_left(t_game mlx)
{
//    char    tile_type;
    int     x;
    int     y;
    
    x = mlx.map_info.p_pos_x;
    y = mlx.map_info.p_pos_y;
    mlx.map_tiles[x][y] = '0';
    mlx.map_tiles[x - 1][y] = 'P';
    return ;
}

void	move_right(t_game mlx)
{
//    char    tile_type;
    int     x;
    int     y;
    
    x = mlx.map_info.p_pos_x;
    y = mlx.map_info.p_pos_y;
    mlx.map_tiles[x][y] = '0';
    mlx.map_tiles[x + 1][y] = 'P';
    return ;
}

int	player_movements(int key_code)
{
	t_game	mlx;
    
	if (key_code == 119)
		move_up(mlx);
	if (key_code == 97)
		move_left(mlx);
	if (key_code == 115)
		move_down(mlx);
	if (key_code == 100)
		move_right(mlx);
	return (0);
}
