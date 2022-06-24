/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:24 by miguel            #+#    #+#             */
/*   Updated: 2022/06/24 13:46:18 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line)
{
	int	x;

	x = 0;
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

int	check_map(int fd)
{
	char	*line;
	size_t	first_line_size;
	int		p;
	int		c;
	int		e;

	line = get_next_line(fd);
	first_line_size = ft_strlen(line);
	while (line)
	{
		if (check_line(line) == 1)
			return (0);
		if (ft_strlen(line) != first_line_size)
			return (0);
		if (ft_strchr_gnl(line, 'P') == 1)
			p++;
		if (ft_strchr_gnl(line, 'C') == 1)
			c++;
		if (ft_strchr_gnl(line, 'E') == 1)
			e++;
		line = get_next_line(fd);
	}
	if (c == 0 || e == 0 || p == 0)
		return (0);
	return (1);
}
