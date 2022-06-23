/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:05 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/23 15:17:33 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_strchr_int(const char *temp, int c)
{
	int	i;

	if (!temp)
		return (0);
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == c)
			return (1);
		i++;
	}
	if (temp[i] == 0 && c != 0)
		return (0);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		x;
	int		y;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1 && s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (s2 && s2[y] != '\0')
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		x;

	if (s1[0] == '\0')
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		dest[x] = s1[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (ft_strlen(s) < len)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else if (start > ft_strlen(s))
		str = (char *)malloc(sizeof(char) * 1);
	else
		str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
