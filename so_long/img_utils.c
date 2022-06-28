/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:03:30 by miguel            #+#    #+#             */
/*   Updated: 2022/06/28 10:02:49 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->ptr + (y * data->size_line
			+ x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	new_sprite(t_mlx mlx, char *path, int x, int y)
{
	mlx.img.ptr = mlx_new_image(mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.ptr = mlx_xpm_file_to_image(mlx.ptr, path, &mlx.x, &mlx.y);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp,
			&mlx.img.size_line, &mlx.img.endian);
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img.ptr, x, y);
}
