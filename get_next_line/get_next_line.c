/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/13 17:57:06 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *buffer)
{
	int		a;

	a = 0;
	if (a != 0 && buffer[a] != '\0')
	{
		if (buffer[a + 1] == '\0')
			return (0);
		a++;
	}
	else if (a != 0 && buffer[a] == '\0')
		return (0);
	while (buffer[a] != '\0' && buffer[a] != '\n')
		a++;
	return (a);
}

int	ft_strchr(const char *s, int c)
{
	size_t		x;
	size_t		y;
	char		chr;
	char		*ptr;

	x = 0;
	y = 0;
	chr = c;
	ptr = (void *)s;
	while (ptr[y])
		y++;
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

	buffer = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	buffer[BUFFER_SIZE + 1] = '\0';
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(buffer, '\n') == 1)
		{
			temp = ft_strjoin(temp, buffer);
			return (temp);
		}
		else
			temp = ft_strjoin(temp, buffer);
	}
	free (buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*temp;
	static int	loop;
	int			new_line_pos;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp && loop == 0)
	{
		temp = malloc(sizeof(char) * 1);
		if (!temp)
			return (NULL);
	}
	temp = read_buffer(fd, temp);
	if (temp[0] == '\0')
		return (NULL);
	new_line_pos = find_new_line(temp);
	if (new_line_pos == 0 && temp[0] != '\n')
		return (NULL);
	loop++;
	str = malloc(sizeof(char) * (new_line_pos + 1));
	if (!str)
		return (NULL);
	str = ft_strdup(temp, str);
	printf("%s", str);
	return (str);
}
