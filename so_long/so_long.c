/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:27:47 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/30 15:18:58 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_img	img;
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1720, 1280);
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mlx_window = mlx_new_window(mlx, 1720, 1280, "window");
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
