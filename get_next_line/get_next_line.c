/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:44:57 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/05 15:42:58 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	char	*buffer;
	char	*str_temp;
	int		x;

	x = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	str_temp = '\0';
	while (ft_strchr(str_temp, 10) == 0 && x > 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x < 1)
		{
			if (x < 0)
				return (NULL);
			else if (!str_temp)
				return (NULL);
			return (str_temp);
		}
		buffer[x] = '\0';
		str_temp = ft_strjoin(str_temp, buffer);
	}
	return (str_temp);
}

int	line_size(char *temp)
{
	int	x;

	x = 0;
	while (temp[x] != '\0' && temp[x] != 10)
		x++;
	if (temp[x] == 10)
		return (x + 1);
	else
		return (x);
}

char	*next_line(char *temp)
{
	char	*next_line;
	int		x;
	int		y;

	if (!temp)
		return (NULL);
	if (ft_strchr(temp, 10) == 0)
		return (NULL);
	x = 0;
	while (temp[x] != 10)
		x++;
	y = 0;
	while (temp[y])
		y++;
	next_line = malloc(sizeof(char) * (y - x));
	x++;
	while (x < y && temp[x] != 10)
	{
		next_line[x] = temp[x];
		x++;
	}
	temp = next_line;
	free (next_line);
	return (next_line);
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
	line = malloc(sizeof(char) * (x + 1));
	if (!line)
		return (NULL);
	y = 0;
	while (y < x && temp[y] != 10)
	{
		line[y] = temp[y];
		y++;
	}
	if (temp[y] == 10)
	{
		line[y] = 10;
		y++;
	}
	line[y] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = ft_read(fd);
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
	int fd = open("/home/miguel/Desktop/get_next_line_test", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}