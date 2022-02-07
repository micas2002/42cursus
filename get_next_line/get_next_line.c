/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:44:57 by mibernar          #+#    #+#             */
/*   Updated: 2022/02/07 16:00:49 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	char	*buffer;
	size_t	size;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size <= 0 || size > BUFFER_SIZE)
	{
		free(buffer);
		return (NULL);
	}
	buffer[size] = '\0';
	return (buffer);
}

char	*find_new_line(int fd, char *str)
{
	char	*new_str;
	char	*temp;

	new_str = ft_read(fd);
	if (!new_str)
		return (str);
	while (ft_strchr(new_str, '\n') == 0)
	{
		temp = str;
		str = ft_strjoin(temp, new_str);
		if (new_str)
			free (new_str);
		if (temp)
			free (temp);
		new_str = ft_read(fd);
		if (!new_str)
			return (str);
	}
	temp = str;
	str = ft_strjoin(temp, new_str);
	if (new_str)
		free(new_str);
	if (temp)
		free(temp);
	return (str);
}

char	*treat_str(char *str)
{
	char	*temp;
	int		x;
	size_t	size;
	size_t	new_line_pos;

	if (ft_strchr(str, '\n') == 0)
		return (str);
	size = ft_strlen(str);
	x = 0;
	while (str[x] != '\n' && str)
		x++;
	new_line_pos = x;
	size = size - new_line_pos;
	temp = malloc(sizeof(char) * (size + 1));
	x = 0;
	new_line_pos++;
	while (str[new_line_pos])
	{
		temp[x] = str[new_line_pos];
		x++;
		new_line_pos++;
	}
	temp[x] = '\0';
	free (str);
	return (temp);
}

char	*treat_temp(char *temp)
{
	char	*new_str;
	int		x;

	if (ft_strchr(temp, '\n') == 0)
		return (temp);
	x = 0;
	while (temp[x] != '\n')
		x++;
	new_str = malloc(sizeof(char) * (x + 2));
	x = 0;
	while (temp[x] != '\n')
	{
		new_str[x] = temp[x];
		x++;
	}
	new_str[x] = temp[x];
	new_str[++x] = '\0';
	free (temp);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = ft_read(fd);
	temp = str;
	str = ft_strjoin(temp, next_line);
	if (next_line)
		free(next_line);
	if (temp)
		free(temp);
	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n') == 0)
		str = find_new_line(fd, str);
	temp = ft_strdup(str);
	temp = treat_temp(temp);
	str = treat_str(str);
	return (temp);
}
