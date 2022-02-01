/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:39:08 by mibernar          #+#    #+#             */
/*   Updated: 2022/02/01 17:12:58 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*rev_str(char *hex_num)
{
	char	*temp;
	int		x;
	int		y;

	x = ft_strlen(hex_num);
	temp = malloc(sizeof(char) * x + 1);
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

static char	*convert(long quotient, char *hex_num)
{
	int		j;
	long	remainder;

	j = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
		{
			if (remainder >= 0)
				hex_num[j++] = 48 + remainder;
			else
				hex_num[j++] = 48 - remainder;
		}
		else
			hex_num[j++] = 87 + remainder;
		quotient = quotient / 16;
	}
	hex_num[j] = '\0';
	return (hex_num);
}

int	ft_printf_x_unsigned(long args)
{
	long	quotient;
	int		i;
	char	*hex_num;
	char	*final;

	quotient = args;
	if (quotient > LONG_MAX)
		quotient = (unsigned long)quotient;
	hex_num = malloc(sizeof(char) * 500);
	final = convert(quotient, hex_num);
	final = rev_str(final);
	i = ft_strlen(final);
	write (1, "0x", 2);
	write (1, final, i);
	free (hex_num);
	free (final);
	return (i);
}

int	ft_printf_p(void *args)
{
	char	*x;
	int		size;
	void	*ptr;

	x = args;
	if (x == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	ptr = x;
	size = ft_printf_x_unsigned((long)ptr);
	return (size + 2);
}
