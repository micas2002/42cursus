/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:05 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/06 12:29:20 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	x;

	x = 0;
	if (s == NULL)
		return (0);
	while (s[x] != '\0')
		x++;
	return (x);
}

int	ft_strchr(char *temp, int c)
{
	int	i;

	i = 0;
	if (temp == NULL)
	{
		return (0);
	}
	while (temp[i] != '\0')
	{
		if (temp[i] == c)
		{
			return (1);
		}
		i++;
	}
	if (temp[i] == 0 && c != 0)
	{
		return (0);
	}
	return (0);
}

static char	*join(char *str, char *s1, char *s2)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (s1)
	{
		while (s1[x] != '\0')
		{
			str[x] = s1[x];
			x++;
		}
	}
	while (s2[y] != '\0')
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	s1 = join(str, s1, s2);
	return (s1);
}
