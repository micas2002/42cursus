/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:35:51 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/12 11:42:45 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	x;
	size_t	y;
	size_t	ctrl_len;

	if ((start >= ft_strlen(s)) || (len == 0))
		return (ft_calloc(1, sizeof(char)));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	x = start;
	y = 0;
	ctrl_len = 0;
	while (ctrl_len < len)
	{
		str[y] = s[x];
		x++;
		y++;
		ctrl_len++;
	}
	str[y] = '\0';
	return (str);
}
