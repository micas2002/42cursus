/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:31 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/14 16:58:16 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x_lower(va_list args)
{
	int		save;
	int		quocient;
	int		hexa_num;
	char	*str;
	char	*temp;

	save = va_arg(args, int);
	quocient = save / 16;
	while (quocient != 0)
	{
		hexa_num = quocient % 16;
		quocient = quocient / 16;
	}
	temp = ft_itoa(hexa_num);
	write (1, "0x", 2);
	write (1, str, 1);
	save = ft_strlen(str) + 2;
	return (save);
}
