/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:24 by miguel            #+#    #+#             */
/*   Updated: 2022/06/23 16:15:40 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line)
{
	int	x;
	
	x = 0;
	while (line)
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != 'C' && line[x] != 'E' && line[x] != 'P')
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

	line = get_next_line(fd);
	while (line)
	{
		printf("\n%s\n", line);
		if (check_line(line) == 1)
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}
