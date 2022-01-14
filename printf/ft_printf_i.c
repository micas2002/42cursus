/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:05:12 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/14 12:22:43 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_i(va_list args)
{
	char	*str;
	int		x;

	str = ft_itoa(va_arg(args, int));
	x = 0;
	while (str)
	{
		write(1, str[x], 1);
		x++;
	}
	write (1, '\0', 1);
	free (str);
	return (x);
}
