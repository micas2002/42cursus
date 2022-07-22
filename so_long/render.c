/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:08:27 by miguel            #+#    #+#             */
/*   Updated: 2022/07/22 16:02:29 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_tiles(t_game mlx)
{
    int     x;
    int     y;
    
    mlx_clear_window(mlx.mlx_ptr, mlx.window);
    x = 0;
    while (x < mlx.map_info.size.y)
    {
        y = 0;
        while (y < mlx.map_info.size.x)
        {
            if (mlx.map_tiles[x][y] == 'P')
                mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			        mlx.player_img.player_img, (y * 64), (x * 64));
            else if (mlx.map_tiles[x][y] == 'C')
                 mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			        mlx.col_img.col_img, (y * 64), (x * 64));
            else if (mlx.map_tiles[x][y] == 'E')
                 mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			        mlx.exit_img.exit_img, (y * 64), (x * 64));
            else if (mlx.map_tiles[x][y] == '1')
                 mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			        mlx.wall_img.wall_img, (y * 64), (x * 64));
            else if (mlx.map_tiles[x][y] == '0')
                 mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			        mlx.floor_img.floor_img, (y * 64), (x * 64));
            y++;
        }
        x++;
    }
}
