/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:36:11 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/16 14:42:57 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx	mlx;
	int		count_w;
	int		count_h = 0;

	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, 900, 900, "game");
	mlx.x = 600;
	mlx.y = 600;
	mlx.img.ptr = mlx_xpm_file_to_image(mlx.ptr, "./space.xpm", &mlx.x, &mlx.y);
	mlx.img.ptr = mlx_new_image(mlx.ptr, 600, 600);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp,
			&mlx.img.size_line, &mlx.img.endian);
	while (++count_h < 600)
	{
		count_w = -1;
		while (++count_w < 600)
		{
			if (count_w % 2)
				mlx.img.data[count_h * 600 + count_w] = 0xFFFFFF;
			else
				mlx.img.data[count_h * 600 + count_w] = 0;
		}
	}
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img.ptr, 0, 0);
	close_game(mlx.window);
	mlx_loop(mlx.ptr);
	return (0);
}
