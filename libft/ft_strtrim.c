/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:02:07 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/05 14:54:31 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check_set(s1[start], (char *)set) == 1)
		start++;
	while (end > start && check_set(s1[end - 1], (char *)set) == 1)
		end--;
	strtrim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!strtrim)
		return (NULL);
	strtrim = ft_substr(s1, start, end - start);
	return (strtrim);
}
