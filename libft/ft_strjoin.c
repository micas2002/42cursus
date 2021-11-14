/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:57:23 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/14 17:35:59 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join(char *str, char *dest, char *src)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (str)
	{
		while (dest)
		{
			str[x] = dest[x];
			x++;
		}
		while (src)
		{
			str[x] = src[y];
			x++;
			y++;
		}
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*dest;
	char	*src;

	dest = s1;
	src = s2;
	str = (char *)malloc(sizeof(char)
			* (strlen((char *)(s1)) + strlen((char *)(s2)) + 1));
	if (!str)
		return (NULL);
	join(str, dest, src);
	return (str);
}
