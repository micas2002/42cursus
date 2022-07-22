/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:24 by miguel            #+#    #+#             */
/*   Updated: 2022/07/22 16:29:37 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_borders(char **map, int y, t_game *mlx)
{
    int x;
    
    x = 0;
    if (y == mlx->map_info.size.y || y == 0)
    {
        while (map[y][x] && map[y][x] != '\n')
        {
            if (map[y][x] == '1')
                x++;
            else
                return (0);
        }
    }
    else
    {
        if (map[y][0] == '1' && map[y][mlx->map_info.size.x - 1] == '1')
            x++;
        else
            return (0);
    }
    return (1);
}

void check_tile(char **map, int x, int y, t_game *mlx)
{
    char    c;

    c = map[y][x];
    if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
        mlx->map_info.true_false = 0;
    if (c == 'P')
    {
        mlx->map_info.player = 1;
        mlx->map_info.p_pos_x = x;
        mlx->map_info.p_pos_y = y;
    }
    if (c == 'E')
        mlx->map_info.exit = 1;
    if (c == 'C')
        mlx->map_info.collectible = 1;
    return ;
}

void  get_map_data(char **map, t_game *mlx)
{
    int         x;

    mlx->map_info.size.x = ft_strlen(map[0]) - 1;
    x = 0;
    while (map[x])
        x++;
    mlx->map_info.size.y = x;
    mlx->map_info.player = 0;
    mlx->map_info.exit = 0;
    mlx->map_info.collectible = 0;
    mlx->map_info.true_false = 1;
    return ;
}

int number_lines(int fd)
{
    int         linecount;
	int		    readcount;
    int         line_size;
	char	c;	

	linecount = 1;
    line_size = 0;
	while (1)
	{
		readcount = read(fd, &c, 1);
        line_size += readcount;
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
            linecount++;
	}
    close(fd);
	return (linecount);
}

int	check_map(int fd, t_game *mlx)
{
    char  **map;
    int     x;
    int     y;
    int     lines;

    lines = number_lines(fd);
    map = (char **)malloc(sizeof(char *) * lines);
    x = -1;
    fd = open(PATH, O_RDONLY);
    while (++x != lines)
        map[x] = get_next_line(fd);
    mlx->map_tiles = map;
    get_map_data(map, mlx);
    y = 0;
    while (map[y])
    {
        if ((int)ft_strlen(map[y]) != mlx->map_info.size.x + 1)
            return (0);
        x = 0;
        while (map[y][x] && map[y][x] != '\n')
        {
            check_tile(map, x, y, mlx);
            if (mlx->map_info.true_false == 0)
                return (0);
            x++;
        }
        if (check_borders(map, y, mlx) == 0)
            return (0);
        y++;
    }
    if (mlx->map_info.collectible == 0 || mlx->map_info.exit == 0 || mlx->map_info.exit == 0)
        return (0);
    return (1);
}
