/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:53:24 by miguel            #+#    #+#             */
/*   Updated: 2022/06/22 16:08:02 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line)
{
	int	x;
	
	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == '0' || line[x] == '1' || line[x] == 'C'
				|| line[x] == 'E' || line[x] == 'P')
				x++;
		return (1);
	}
	return (0);
}

int	check_map(int fd)
{
	char	*line;
	
	line = get_next_line(fd);
	printf("here\n");
	if (!line)
		return (0);
	while (line)
	{
		if (check_line(line) == 1)
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}
