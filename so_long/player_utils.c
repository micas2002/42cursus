/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:21:35 by miguel            #+#    #+#             */
/*   Updated: 2022/07/28 13:10:19 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to(t_game *mlx, t_tile *tile)
{
    if(tile->tile_type == FLOOR)
        move_to_floor(mlx, tile);
}

int	player_movements(int key_code, t_game *mlx)
{
	if (key_code == 119)
		move_to(mlx, mlx->player.tile->up);
	if (key_code == 115)
        move_to(mlx, mlx->player.tile->down);
	if (key_code == 97)
        move_to(mlx, mlx->player.tile->left);
	if (key_code == 100)
        move_to(mlx, mlx->player.tile->right);
	return (0);
}