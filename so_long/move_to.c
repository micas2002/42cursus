/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:38:45 by miguel            #+#    #+#             */
/*   Updated: 2022/07/28 12:52:55 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_to_floor(t_game *mlx, t_tile *tile)
{
    tile->tile_type = PLAYER;
    if (mlx->player.tile->tile_type != EXIT)
		mlx->player.tile->tile_type = FLOOR;
	mlx->player.tile = tile;
}