/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/07 12:52:28 by mibernar         ###   ########.fr       */
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

char	*read_buffer(int fd, char *temp)
{
	char	*buffer;
	char	*str;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
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
	if (temp[0] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	free (buffer);
	str = temp;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*temp;
	int			new_line_pos;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp)
		temp = malloc(sizeof(char) * 1);
	temp = read_buffer(fd, temp);
	if (!temp)
	{
		free (temp);
		return (temp);
	}
	new_line_pos = find_new_line(temp);
	str = malloc(sizeof(char) * (new_line_pos + 1));
	if (!str)
		return (NULL);
	free (str);
	str = ft_strdup(temp, str);
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