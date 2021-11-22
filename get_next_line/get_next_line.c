/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/22 16:17:36 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			size;

	if (fd < 0)
		return (NULL);
	while (read(fd, buffer, 23) > 0)
	{
		size = read(fd, buffer, 23);
		buffer[size] = '\0';
		if (str[fd] == NULL)
			str = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin((const char *)str[fd], buffer);
			free (str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	printf("%s", buffer);
	return (buffer);
}

int main(void)
{
	int fd = open("/home/miguel/Desktop/get_next_line.txt", O_RDONLY);

	get_next_line(fd);
	close(fd);
}
