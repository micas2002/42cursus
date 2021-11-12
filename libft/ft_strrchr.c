/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:49:06 by mibernar          #+#    #+#             */
/*   Updated: 2021/10/28 15:04:44 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	*ptr;

	x = 0;
	ptr = (void *)s;
	while (ptr[x] != '\0')
	{
		x++;
	}
	while (x >= 0)
	{
		if (ptr[x] == c)
		{
			return (&ptr[x]);
		}
		x--;
	}
	return (NULL);
}
