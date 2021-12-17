/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:44:57 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/17 12:56:38 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *temp)
{
	char	buffer[BUFFER_SIZE + 1];
	int		x;

	x = BUFFER_SIZE;
	while (!ft_strchr(temp, 10) && x > 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x < 1)
		{
			if (!temp)
				return (NULL);
			return (temp);
		}
		buffer[x] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	return (temp);
}

int	line_size(char *temp)
{
	int	x;

	x = 0;
	while (temp[x] != '\0' && temp[x] != 10)
		x++;
	return (x);
}

char	*next_line(char *temp)
{
	char	*next_line;
	int		x;
	int		y;

	if (!temp)
		return (NULL);
	x = line_size(temp);
	next_line = malloc(sizeof(char) * x);
	y = 0;
	if (temp[x + 1] == '\0')
	{
		free (temp);
		return (NULL);
	}
	while (temp && temp[x] != 10)
	{
		next_line[y] = temp[x];
		x++;
		y++;
	}
	if (temp[x] == 10)
	{
		next_line[y] = temp[x];
		x++;
		y++;
	}
	next_line[x] = '\0';
	temp = next_line;
	free (next_line);
	return (temp);
}

char	*write_line(char *temp)
{
	char	*line;
	int		x;
	int		y;

	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
		return (NULL);
	x = line_size(temp);
	line = malloc(sizeof(char) * x);
	if (!line)
		return (NULL);
	y = 0;
	while (y < x && temp[y] != 10)
	{
		line[y] = temp[y];
		y++;
	}
	line[y] = temp[y];
	line[y + 1] = '\0';
	temp = line;
	free (line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = ft_read(fd, temp);
	str = write_line(temp);
	temp = next_line(temp);
	if (!str && !temp)
	{
		free (str);
		free (temp);
		return (NULL);
	}
	return (str);
}
int main(void)
{
	int fd = open("/Users/mibernar/Desktop/get_next_line_test.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
}