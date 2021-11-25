/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/25 12:45:06 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *buffer)
{
	static int	a;

	a = 0;
	while (buffer[a] == '\n')
		a++;
	while (buffer[a] != '\n')
		a++;
	return (a);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE];
	static int	new_line_pos;
	static int	i;
	int			x;

	if (fd < 0)
		return (NULL);
	new_line_pos = find_new_line(buffer);
	x = 0;
	i = 0;
	if (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = malloc(sizeof(char) * BUFFER_SIZE);
		if (str[0] == '\0')
			while (i < new_line_pos)
			{
				str[x] = buffer[i];
				i++;
				x++;
			}
		else
		{
			free (str);
			while (i < new_line_pos)
			{
				str[x] = buffer[i];
				i++;
				x++;
			}
		}
	}
	printf("%s", str);
	return (str);
}

int main(void)
{
	int fd = open("/Users/mibernar/Desktop/get_next_line_test.txt", O_RDONLY);

	get_next_line(fd);
	close(fd);
}