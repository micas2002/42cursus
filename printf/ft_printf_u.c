/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:28 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/19 15:18:13 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenght_int(long int n)
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

void	write_numbers(long int n_value, char *str, int i)
{
	while (n_value > 0)
	{
		str[i] = '0' + (n_value % 10);
		n_value = n_value / 10;
		i--;
	}
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char		*str;
	int			i;
	long int	n_value;

	n_value = n;
	str = (char *)malloc(sizeof(char) * (lenght_int(n) + 1));
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

int	ft_printf_u(va_list args)
{
	unsigned int	a;
	char			*str;

	a = va_arg(args, unsigned int);
	if (a < 0)
		a = 4294967295 + a;
	str = ft_unsigned_itoa(a);
	a = ft_strlen(str);
	write (1, str, a);
	free (str);
	return (a);
}
