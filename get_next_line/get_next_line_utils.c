/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:05 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/15 15:59:45 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	if (s == NULL)
		return (0);
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == 0 && c != 0)
		return (NULL);
	return (&s[i]);
}

static char	*join(char *str, const char *s1, const char *s2)
{
	int	x;
	int	y;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)(s1)) + ft_strlen((char *)(s2)) + 1));
	if (!str)
		return (NULL);
	str = join(str, s1, s2);
	return (str);
}
