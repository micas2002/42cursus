/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:11:07 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/04 16:49:24 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line_temp(char *buffer)
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

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

static char	join(char *str, const char *s1, const char *s2)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	return (*str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)(s1)) + ft_strlen((char *)(s2)) + 1));
	if (!str)
		return (NULL);
	join(str, s1, s2);
	return (str);
}
