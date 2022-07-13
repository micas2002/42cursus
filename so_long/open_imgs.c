/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:07:42 by miguel            #+#    #+#             */
/*   Updated: 2022/07/13 12:18:14 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void    open_floor(t_game *mlx)
{
    mlx->player_img.player_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
        "./space.xpm", &mlx->img_size.x, &mlx->img_size.y);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, )
}
*/
void    open_players(t_game *mlx)
{
    mlx->player_img.player_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
        "./character.xpm", &mlx->img_size.x, &mlx->img_size.y);
//   mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->player_img.player_img, 0, 0);
}

void    open_imgs(t_game *mlx)
{
//    open_walls(mlx);
//   open_floor(mlx);
    open_players(mlx);
//   open_colectibles(mlx);
//  open_doors(mlx);
}
