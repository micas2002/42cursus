/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:13:08 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/15 10:40:08 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	wrd_count;

	wrd_count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			wrd_count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (wrd_count);
}

static int	str_size(char const *s, char c, size_t a)
{
	size_t	i;

	i = a;
	if (s[i] == c)
	{
		while (s[i] == c)
			i++;
	}
	while (s[i] != c)
		i++;
	return (i);
}

static int	trim_size(char const *s, char c, size_t a)
{
	size_t	i;
	size_t	x;

	i = a;
	x = 0;
	if (s[i] == c)
	{
		while (s[i] == c)
			i++;
	}
	while (s[i] != c)
	{
		i++;
		x++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	size_t	wrd_number;
	size_t	i;
	size_t	x;
	size_t	a;
	char	**str;

	i = 0;
	a = 0;
	if (!s || !c)
		return (NULL);
	wrd_number = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (wrd_number));
	if (!str)
		return (NULL);
	while (i < wrd_number)
	{
		x = trim_size(s, c, a);
		a = str_size(s, c, a);
		str[i] = malloc(sizeof(char) * (x + 1));
		str[i] = ft_substr(s, (unsigned int)(a - x), x);
		i++;
	}
	return (str);
}
