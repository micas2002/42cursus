/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:57:28 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/13 16:38:48 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(const char *str, const char *to_find, int x)
{
	int	y;

	y = 0;
	while (to_find[y] != '\0')
	{
		if (to_find[y] == str[x])
		{
			x++;
			y++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;

	while (haystack[x] != '\0' && x < len)
	{
		if (haystack[x] == needle[0])
		{
			if (ft_strcmp(haystack, needle, x) == 1)
			{
				return ((char *)haystack + x);
			}
			else
				return (NULL);
		}
		else if (needle[0] == '\0')
		{
			return ((char *)haystack);
		}
		x++;
		len--;
	}
	return (0);
}
