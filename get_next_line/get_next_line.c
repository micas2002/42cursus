/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/03 13:43:23 by mibernar         ###   ########.fr       */
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
	{
		if (buffer[a + 1] == '\0')
			return (0);
		a++;
	}
	else if (a != 0 && buffer[a] == '\0')
		return (0);
	while (buffer[a] != '\n' && buffer[a] != '\0')
		a++;
	return (a);
}

char	*read_buffer(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*temp;
	char	*str;

	temp = NULL;
	while (read(fd, buffer, BUFFER_SIZE) > 0 && ft_strchr(buffer, 10) == NULL)
		temp = ft_strjoin(temp, buffer);
	str = temp;
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*temp;
	int				buff_pos;
	int				new_line_pos;
	static int		loop;
	int				x;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (loop == 0)
		temp = read_buffer(fd);
	loop++;
	new_line_pos = find_new_line(temp);
	if (new_line_pos == 0)
		return (NULL);
	free (str);
	str = malloc(sizeof(char) * (str_size(temp, new_line_pos)) + 1);
	if (!str)
		return (NULL);
	buff_pos = new_line_pos - str_size(temp, new_line_pos);
	x = 0;
	while (x < str_size(temp, new_line_pos) && temp[buff_pos] != '\n')
		str[x++] = temp[buff_pos++];
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
