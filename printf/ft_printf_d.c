/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:23 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/21 16:13:25 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(va_list args)
{
	char	*str;
	int		size;

	str = ft_itoa(va_arg(args, int));
	size = ft_strlen(str);
	write(1, str, size);
	free (str);
	return (size);
}