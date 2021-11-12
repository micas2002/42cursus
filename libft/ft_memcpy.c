/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:48:52 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/11 12:19:18 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	x;

	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	x = 0;
	while (x < n)
	{
		ptr1[x] = ptr2[x];
		x++;
	}
	return (dst);
}
