/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:05:12 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/19 15:38:05 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_i(va_list args)
{
	char	*str;
	int		size;

	str = ft_itoa(va_arg(args, int));
	size = strlen(str);
	write(1, str, size);
	free (str);
	return (size);
}
