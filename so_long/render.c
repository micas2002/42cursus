/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:08:27 by miguel            #+#    #+#             */
/*   Updated: 2022/07/08 15:12:31 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_tiles(t_game mlx)
{
    t_img   tile;
    int     x;
    int     y;

    mlx_clear_window(mlx.mlx_ptr, mlx.window);
    x = 0;
    while (mlx.map_tiles[x] != NULL)
    {
        y = 0;
        while (&mlx.map_tiles[x][y])
        {
            if (&mlx.map_tiles[x][y] == 'P')
                mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, 
                        mlx.player_img.player_img, tile.pos.x, tile.pos.y)
            else if (&mlx.map_tiles[x][y] == 'C')
            
            else if (&mlx.map_tiles[x][y] == 'E')
            
            else if (&mlx.map_tiles[x][y] == '1')
            
            else if (&mlx.map_tiles[x][y] == '0')
            
            y++;
        }
        x++;
    }
}
