/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/23 16:51:13 by mibernar         ###   ########.fr       */
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
		str = malloc(sizeof(char) * (size + 1));
		str[size] = '\0';
		if (str[0] == '\0')
			str = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str, buffer);
			free (str);
			str = temp;
		}
		if (ft_strchr(str, '\n'))
			break ;
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
