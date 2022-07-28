/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:36:20 by miguel            #+#    #+#             */
/*   Updated: 2022/07/28 13:26:15 by miguel           ###   ########.fr       */
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

void	setup_tile(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].og_type = tilemap[y][x].tile_type;
	tilemap[y][x].pos.x = x * 64;
	tilemap[y][x].pos.y = y * 64;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
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
        {
            tile_map[x][y].tile_type = get_type(mlx->map_tiles[x][y]);
            setup_tile(tile_map, y, x);
        }
        x++;
    }
    return (tile_map);
}