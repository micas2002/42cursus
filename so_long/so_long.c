/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:26:39 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/03 13:37:56 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_map(void *mlx)
{
	void	*img;
	char	*img_path;
	int		img_width;
	int		img_height;

	img_path = "./img.xpm";
	img_width = 600;
	img_height = 600;
	img = mlx_xpm_file_to_image(mlx, img_path, &img_width, &img_height);
	return (img);
}

int	paint_window(t_img	img)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	color = 0;
	while (x != 600)
	{
		y = 0;
		while (y != 600 && y >= 0)
		{
			my_mlx_pixel_put(&img, x, y, color + 80);
			y++;
		}
		x++;
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_vars	vars;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "game");
	img.img = mlx_new_image(mlx, 600, 600);
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.img = get_map(mlx);
	paint_window(img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, (1L << 0), close_window, &vars);
	mlx_loop(mlx);
}
