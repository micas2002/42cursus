/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:33 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/26 17:20:20 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*rev_str(char *hex_num)
{
	char	*temp;
	int		x;
	int		y;

	x = ft_strlen(hex_num);
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

int	ft_printf_x_upper(int args)
{
	long	quotient;
	long	remainder;
	int		i;
	int		j;
	char	*hex_num;

	hex_num = malloc(sizeof(char) * 500);
	quotient = args;
	j = 0;
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
	i = ft_strlen(hex_num);
	write (1, hex_num, i);
	free (hex_num);
	return (i + 2);
}
