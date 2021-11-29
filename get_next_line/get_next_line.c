/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/26 13:10:01 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_size(char *buffer, int new_line_pos)
{
	int	size;
	int	x;

	x = new_line_pos - 1;
	size = 0;
	while (buffer[x] != '\n' && buffer[x] != '\0')
	{
		size++;
		x--;
	}
	return (size);
}

int	find_new_line(char *buffer)
{
	static int	a;

	while (buffer[a] == '\n' && buffer[a] != '\0')
		a++;
	while (buffer[a] != '\n' && buffer[a] != '\0')
		a++;
	return (a);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE];
	int			new_line_pos;
	int			size;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, BUFFER_SIZE) < 1)
		return (NULL);
	new_line_pos = find_new_line(buffer);
	size = str_size(buffer, new_line_pos);
	str = malloc(sizeof(char) * (size + 1));
	str[size + 1] = '\0';
	while (size > 0)
	{
		str[size] = buffer[new_line_pos];
		size--;
		new_line_pos--;
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