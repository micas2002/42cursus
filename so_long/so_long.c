/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:36:11 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/23 16:57:17 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(int fd)
{
	t_mlx	mlx;

	if (check_map(fd) == 0)
	{
		ft_putendl_fd("INVALID MAP", 2);
		return ;
	}
	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "game");
	new_sprite(mlx, "./space.xpm", 0, 0);
	new_sprite(mlx, "./character.xpm", 400, 400);
	mlx_key_hook(mlx.window, close_game, &mlx);
	mlx_hook(mlx.window, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.ptr);
}

int	main(void)
{
	int	fd;

	fd = open("/home/miguel/projects/42cursus/so_long/map.ber", O_RDONLY);
	so_long(fd);
	return (0);
}
