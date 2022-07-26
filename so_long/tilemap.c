/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:36:20 by miguel            #+#    #+#             */
/*   Updated: 2022/07/26 17:20:53 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile  **tilemap_alloc(t_game *mlx)
{
    t_tile  **map;
    int     x;
    
    map = malloc(sizeof(t_tile *) * mlx->map_info.size.y + 1);
    if (!map)
        return (NULL);
    x = 0;
    while (mlx->map_tiles[x])
    {
        map[x] = malloc(sizeof(t_tile) * mlx->map_info.size.x + 1);
        if (!map)
        {
            while (x > 0)
				free(map[--x]);
			return (NULL);
		}
		x++;
	}
	return(map);
}

char  get_type(char tile)
{
    if (tile == '1')
        return ('1');
    else if (tile == '0')
        return ('0');
    else if (tile == 'P')
        return ('P');
    else if (tile == 'C')
        return ('C');
    else
        return ('E');
}

t_tile    **generate_tilemap(t_game *mlx)
{
    t_tile  **tile_map;
    int     x;
    int     y;
    
    tile_map = tilemap_alloc(mlx);
    if (!tile_map)
        return (NULL);
    x = 0;
    while (mlx->map_tiles[x])
    {
        y = -1;
        while (mlx->map_tiles[x][y++] != '\0')
            tile_map[x][y].tile_type = get_type(mlx->map_tiles[x][y]);
        x++;
    }
    return (tile_map);
}