/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:14:53 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/19 12:41:24 by miguel           ###   ########.fr       */
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
