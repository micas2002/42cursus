/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:44:57 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/15 17:20:03 by mibernar         ###   ########.fr       */
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
			return (NULL);
		buffer[x] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	return (temp);
}

int	line_size(char *temp)
{
	int	x;

	x = 0;
	while (temp && temp[x] != 10)
		x++;
	return (x);
}

char	*next_line(char *temp)
{
	char	*next_line;
	int		x;
	int		y;

	x = line_size(temp);
	next_line = malloc(sizeof(char) * (x + 1));
	y = 0;
	if (!temp)
		return (NULL);
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
	return (next_line);
}

char	*write_line(char *temp)
{
	char	*line;
	int		x;

	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
		return (NULL);
	x = line_size(temp);
	line = malloc(sizeof(char) * (x + 1));
	if (!line)
		return (NULL);
	x = 0;
	while (temp && temp[x] != 10)
	{
		line[x] = temp[x];
		x++;
	}
	line[x] = temp[x];
	line[x + 1] = '\0';
	return (line);
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
	printf("%s", str);
	return (str);
}
