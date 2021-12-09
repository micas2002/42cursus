/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:11:07 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/09 13:08:48 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int			x;
	static int	y;

	x = 0;
	while (src[y] != '\0')
	{
		if (src[y] == '\n')
		{
			dst[x] = src[y];
			x++;
			y++;
			break ;
		}
		else
		{
			dst[x] = src[y];
			x++;
			y++;
		}
	}
	dst[x] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1, char *str)
{
	ft_strcpy(str, s1);
	return (str);
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