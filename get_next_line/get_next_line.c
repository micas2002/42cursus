/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/24 17:13:21 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *buffer, int x)
{
	static int	a;

	a = 0;
	while (buffer[a] != '\n')
	{
		a++;
		x++;
	}
	a++;
	return (x);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer[BUFFER_SIZE];
	int			x;
	int			y;
	static int	new_line_position;

	if (fd < 0)
		return (NULL);
	x = 0;
	new_line_position = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		find_new_line(*buffer, new_line_position);
		free(str);
		while (x < new_line_position)
		{
			str[x] = buffer[y];
			x++;
			y++;
		}
	}
	printf("%s", str);
	return (str);
}

int main(void)
{
	int fd = open("/home/miguel/Desktop/get_next_line_test", O_RDONLY);

	get_next_line(fd);
	close(fd);
}