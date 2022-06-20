/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:36:11 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/20 15:26:42 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	t_mlx	mlx;


	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "game");
	mlx.x = WIN_WIDTH;
	mlx.y = WIN_HEIGHT;
	mlx.img.ptr = mlx_new_image(mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.ptr = mlx_xpm_file_to_image(mlx.ptr, "./space.xpm", &mlx.x, &mlx.y);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp,
			&mlx.img.size_line, &mlx.img.endian);
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img.ptr, 0, 0);
	close_game(mlx.window);
	mlx_loop(mlx.ptr);
	return (0);
}