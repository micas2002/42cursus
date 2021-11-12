/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:40:35 by mibernar          #+#    #+#             */
/*   Updated: 2021/10/28 15:03:09 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	int		y;
	char	*ptr;

	x = 0;
	y = 0;
	ptr = (void *)s;
	while (ptr[y] != '\0')
	{
		y++;
	}
	while (x <= y)
	{
		if (ptr[x] == c)
		{
			return (&ptr[x]);
		}
		x++;
	}
	return (NULL);
}
