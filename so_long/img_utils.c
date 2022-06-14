/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:03:30 by miguel            #+#    #+#             */
/*   Updated: 2022/06/14 13:48:58 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_size
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;
	
	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

t_img	new_img(void *mlx, int width, int height)
{
	t_img	img;
	
	img.reference = mlx_new_image(mlx, width, height);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}