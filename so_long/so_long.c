/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:35:14 by miguel            #+#    #+#             */
/*   Updated: 2022/06/14 13:49:56 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(void *mlx_win)
{
	t_vars	vars;

	mlx_hook(mlx_win, 2, (1L << 0), close_window, &vars);
	mlx_hook(mlx_win, 17, (1L << 17), close_window, &vars);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "game");
	img = new_sprite(mlx, "./space.xpm");
	mlx_put_image_to_window(mlx, mlx_win, img.reference, 0, 0);
	close_game(mlx_win);
	mlx_loop(mlx);
    return (0);
}
