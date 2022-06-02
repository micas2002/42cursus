/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:27:47 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/02 14:21:09 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_vars	vars;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "game");
	img.img = mlx_new_image(mlx, 600, 600);
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	x = 0;
	while (x != 600)
	{
		y = 0;
		while (y != 300 && y >= 0)
		{
			my_mlx_pixel_put(&img, x, y, 0x32a852);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, (1L << 0), close_window, &vars);
	mlx_loop(mlx);
}
