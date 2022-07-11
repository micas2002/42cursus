/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:24 by miguel            #+#    #+#             */
/*   Updated: 2022/07/11 12:01:07 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_borders(char **map, int y, t_map_info data)
{
    int x;
    
    x = 0;
    if (y == data.size.y || y == 0)
    {
        while (map[y][x])
        {
            if (map[y][x] == '1')
                x++;
            else
                return (0);
        }
    }
    else
    {
        if (map[y][0] == '1' && map[y][data.size.x] == '1')
            x++;
        else
            return (0);
    }
    return (1);
}

int check_tile(char **map, int x, int y)
{
    char    c;

    c = map[y][x];
    if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
        return (0);
    return (1);
}

t_map_info  get_map_data(char **map)
{
    t_map_info  data;
    int         x;

    data.size.x = ft_strlen(map[0]);
    x = -1;
    while (map[++x])
        data.size.y++;
    data.player = 0;
    data.exit = 0;
    data.collectible = 0;
    return (data);
}

int	check_map(int fd)
{
    t_map_info  data;
    char  **map;
    int     x;
    int     y;

    x = 0;
    while (map[x])
        map[x] = get_next_line(fd);
    data = get_map_data(map);
    y = 0;
    while (map[y])
    {
        if ((int)ft_strlen(map[y]) != data.size.x)
            return (0);
        x = 0;
        while (map[y][x] && map[y][x] != '\n')
        {
            if (check_tile(map, x, y) == 0)
                return (0);
        }
        if (check_borders(map, y, data) == 0)
            return (0);
    }
    if (data.collectible == 0 || data.exit == 0 || data.exit == 0)
        return (0);
    return (1);
}
