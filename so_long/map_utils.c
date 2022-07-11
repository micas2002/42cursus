/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:24 by miguel            #+#    #+#             */
/*   Updated: 2022/07/11 18:41:39 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_borders(char **map, int y, t_map_info data)
{
    int x;
    
    x = 0;
    if (y == data.size.y || y == 0)
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
        if (map[y][0] == '1' && map[y][data.size.x - 1] == '1')
            x++;
        else
            return (0);
    }
    return (1);
}

t_map_info check_tile(char **map, int x, int y, t_map_info data)
{
    char    c;

    c = map[y][x];
    if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
        data.true_false = 0;
    if (c == 'P')
        data.player = 1;
    if (c == 'E')
        data.exit = 1;
    if (c == 'C')
        data.collectible = 1;
    return (data);
}

t_map_info  get_map_data(char **map)
{
    t_map_info  data;
    int         x;

    data.size.x = ft_strlen(map[0]) - 1;
    x = -1;
    while (map[++x])
        data.size.y++;
    data.player = 0;
    data.exit = 0;
    data.collectible = 0;
    return (data);
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

int	check_map(int fd)
{
    t_map_info  data;
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
    data = get_map_data(map);
    y = 0;
    while (map[y])
    {
        if ((int)ft_strlen(map[y]) != data.size.x + 1)
            return (0);
        x = 0;
        while (map[y][x] && map[y][x] != '\n')
        {
            data = check_tile(map, x, y, data);
            if (data.true_false == 0)
                return (0);
            x++;
        }
        if (check_borders(map, y, data) == 0)
            return (0);
        y++;
    }
    if (data.collectible == 0 || data.exit == 0 || data.exit == 0)
        return (0);
    return (1);
}
