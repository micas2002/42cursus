/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/29 13:41:51 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_size(char *buffer, int new_line_pos)
{
	int	size;
	int	x;

	x = new_line_pos - 1;
	size = 0;
	while (buffer[x] != '\n' && x >= 0)
	{
		size++;
		x--;
	}
	return (size);
}

int	find_new_line(char *buffer)
{
	static int	a;

	if (a != 0 && buffer[a] != '\0')
		a++;
	while (buffer[a] != '\n' && buffer[a] != '\0')
		a++;
	return (a);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE];
	int			buff_pos;
	int			new_line_pos;
	int			x;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	new_line_pos = find_new_line(buffer);
	str = malloc(sizeof(char) * (str_size(buffer, new_line_pos)) + 1);
	free (str);
	buff_pos = new_line_pos - str_size(buffer, new_line_pos);
	x = 0;
	while (x < str_size(buffer, new_line_pos))
	{
		str[x] = buffer[buff_pos];
		x++;
		buff_pos++;
	}
	str[x] = '\0';
	printf("%s\n", str);
	return (str);
}

int main(void)
{
	int fd = open("/Users/mibernar/Desktop/get_next_line_test.txt", O_RDONLY);

	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
}