/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:33 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/17 17:21:20 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_upper(char *hex_num)
{
	int	x;

	x = 0;
	while (hex_num[x] != '\0')
	{
		if (hex_num[x] > 96 && hex_num[x] < 123)
			hex_num[x] = hex_num[x] - 32;
		x++;
	}
	hex_num[x] = '\0';
	return (hex_num);
}

char	*rev_str(char *hex_num)
{
	char	*temp;
	int		x;
	int		y;

	x = strlen(hex_num);
	temp = malloc(sizeof(char) * x);
	y = 0;
	x -= 1;
	while (hex_num && x >= 0)
	{
		temp[y] = hex_num[x];
		x--;
		y++;
	}
	temp[y] = '\0';
	return (temp);
}

int	ft_printf_x_upper(va_list args)
{
	long	quotient;
	long	remainder;
	int		i;
	int		j;
	char	*hex_num;

	hex_num = malloc(sizeof(char) * 500);
	quotient = va_arg(args, int);
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hex_num[j++] = 48 + remainder;
		else
			hex_num[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	hex_num[j] = '\0';
	hex_num = rev_str(hex_num);
	hex_num = ft_upper(hex_num);
	i = ft_strlen(hex_num);
	write (1, hex_num, i);
	free (hex_num);
	return (i);
}
