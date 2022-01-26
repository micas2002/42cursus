/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:14:53 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/26 15:27:29 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght_int(long int n)
{
	long int	x;
	long int	temp;

	x = 0;
	temp = n;
	if (n == 0)
		return (1);
	while (temp != 0)
	{
		temp = temp / 10;
		x++;
	}
	if (n < 0)
		return (x + 1);
	return (x);
}

static void	write_numbers(long int n_value, char *str, int i)
{
	while (n_value > 0)
	{
		str[i] = '0' + (n_value % 10);
		n_value = n_value / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	n_value;

	n_value = n;
	str = malloc(sizeof(char) * (lenght_int(n) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (n_value == 0)
		str[0] = '0';
	if (n_value > 0)
		i = lenght_int(n_value) - 1;
	if (n_value < 0)
	{
		str[0] = '-';
		n_value *= -1;
		i = lenght_int(n_value);
	}
	write_numbers(n_value, str, i);
	str[lenght_int(n)] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}
