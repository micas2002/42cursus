/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/09 13:28:27 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *buffer)
{
	int	a;

	a = 0;
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

int	ft_strchr(const char *s, int c)
{
	int		x;
	int		y;
	char	chr;
	char	*ptr;

	x = 0;
	y = 0;
	chr = c;
	ptr = (void *)s;
	while (ptr[y] != '\0')
	{
		y++;
	}
	while (x <= y)
	{
		if (ptr[x] == chr)
			return (1);
		x++;
	}
	return (0);
}

char	*read_buffer(int fd, char *temp, int loop)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(buffer, '\n') == 1)
		{
			temp = ft_strjoin(temp, buffer);
			break ;
		}
		else
			temp = ft_strjoin(temp, buffer);
	}
	if (loop != 0 && !temp)
	{
		free (buffer);
		return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	static char	*temp;
	int			new_line_pos;
	static int	loop;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp)
		temp = malloc(sizeof(char) * 1);
	temp = read_buffer(fd, temp, loop);
	new_line_pos = find_new_line(temp);
	if (!str)
		free (str);
	str = malloc(sizeof(char) * (ft_strlen(temp) + 1));
	if (!str)
		return (NULL);
	str = ft_strdup(temp, str);
	if (loop != 0 && new_line_pos == 0)
	{
		free (str);
		free (temp);
		return (NULL);
	}
	loop++;
	printf("%s", str);
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