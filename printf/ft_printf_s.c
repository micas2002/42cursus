/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:50:08 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/14 12:51:56 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(va_list args)
{
	char	*temp;
	int		x;

	temp = va_arg(args, char *);
	x = 0;
	while (temp[x] != '\0')
	{
		write(1, temp[x], 1);
		x++;
	}
	write (1, '\0', 1);
	free (temp);
	return (x);
}
