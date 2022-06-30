/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:21:35 by miguel            #+#    #+#             */
/*   Updated: 2022/06/30 16:22:05 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx mlx)
{
	mlx_destroy_image(mlx.ptr, mlx.img.ptr);
}

void	move_down(t_mlx mlx)
{
	mlx_destroy_image(mlx.ptr, mlx.img.ptr);
}

void	move_left(t_mlx mlx)
{
	mlx_destroy_image(mlx.ptr, mlx.img.ptr);
}

void	move_right(t_mlx mlx)
{
	mlx_destroy_image(mlx.ptr, mlx.img.ptr);
}

int	player_movements(int key_code)
{
	t_mlx	mlx;

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
