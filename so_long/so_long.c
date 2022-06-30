/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:36:11 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/30 16:37:35 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(int fd)
{
	t_mlx	mlx;

	if (check_map(fd) == 0)
	{
		ft_putendl_fd("ERROR\nINVALID MAP", 2);
		return ;
	}
	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "game");
	new_sprite(mlx, "./space.xpm", 0, 0);
	new_sprite(mlx, "./character.xpm", 400, 400);
	mlx_key_hook(mlx.window, keys, &mlx);
	mlx_hook(mlx.window, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.ptr);
}

int	main(int argc, char **argv)
{
	char	*path;
	int		fd;
	int		x;

	path = argv[1];
	if (argc != 2)
		return (0);
	x = 0;
	while (path[x])
	{
		if (path[x] == '.' && path[x + 1] == 'b'
			&& path[x + 2] == 'e' && path[x + 3] == 'r')
			if (path[x + 4] == '\0')
				break ;
		x++;
	}
	if (path[x] == '\0')
	{
		ft_putendl_fd("ERROR\nINVALID FILE TYPE", 2);
		return (0);
	}
	fd = open(path, O_RDONLY);
	so_long(fd);
	return (0);
}
