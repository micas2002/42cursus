/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:10:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/04 17:23:10 by mibernar         ###   ########.fr       */
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

	temp = malloc(sizeof(char) * 1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(buffer, 10) == 1)
		{
			temp = ft_strjoin(temp, buffer);
			break ;
		}
		else
			temp = ft_strjoin(temp, buffer);
	}
	str = temp;
	return (str);
}

char	*ft_loop(char *str, char *temp, int new_line_pos, int buff_pos)
{
	int		x;

	x = 0;
	while (x < str_size(temp, new_line_pos) && temp[buff_pos] != '\n')
		str[x++] = temp[buff_pos++];
	str[x] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*temp;
	int				buff_pos;
	int				new_line_pos;
	static int		loop;

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
	str = ft_loop(str, temp, new_line_pos, buff_pos);
	printf("%s\n", str);
	return (str);
}

int main(void)
{
	int fd = open("/home/miguel/Desktop/get_next_line_test", O_RDONLY);

	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
}
