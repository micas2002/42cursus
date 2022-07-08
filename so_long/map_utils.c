/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:24 by miguel            #+#    #+#             */
/*   Updated: 2022/07/08 15:19:56 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(char *line)
{
	int	x;

	x = 0;
	while (line && line[x] != '\n')
	{
		if (line[x] == '1')
			x++;
		else
			return (0);
	}
	if ((line[x] == '\n' && line[x + 1] == '\0') || line[x] == '\0')
		return (1);
	return (0);
}

int	check_line_content(char *line, size_t first_line_size)
{
	int	x;

	x = 0;
	if (ft_strlen(line) != first_line_size)
		return (0);
	while (line)
	{
		if (line[x] != '0' && line[x] != '1'
			&& line[x] != 'C' && line[x] != 'E' && line[x] != 'P')
		{
			if (line[x] == '\n' && line[x + 1] == '\0')
				return (0);
			return (1);
		}
		x++;
	}
	return (0);
}

int	check_map_loop(int fd, char *line, size_t first_line_size, t_game map)
{
	int		p;
	int		c;
	int		e;
    int     x;
	char	*last_line;

	p = 0;
	c = 0;
	e = 0;
    x = 0;
	while (line)
	{
		last_line = line;
		if (line[0] != '1' || line[first_line_size - 2] != '1'
			|| check_line_content(line, first_line_size) == 1)
			return (0);
		if (ft_strchr_gnl(line, 'P') == 1)
			p++;
		if (ft_strchr_gnl(line, 'C') == 1)
			c++;
		if (ft_strchr_gnl(line, 'E') == 1)
			e++;
		line = get_next_line(fd);
        map.map_tiles[x++] = line;
	}
	if (c == 0 || e == 0 || p == 0 || check_borders(last_line) == 0)
		return (0);
	return (1);
}

int	check_map(int fd)
{
    t_game  map;

	char	*line;
	size_t	first_line_size;

	line = get_next_line(fd);
	if (check_borders(line) == 0)
		return (0);
	first_line_size = ft_strlen(line);
	line = get_next_line(fd);
    map.map_tiles[0] = line;
	if (check_map_loop(fd, line, first_line_size, map) == 0)
		return (0);
	return (1);
}