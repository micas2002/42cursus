/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:50:08 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/25 16:16:04 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(va_list args)
{
	char	*temp;
	int		size;

	temp = va_arg(args, char *);
	size = ft_strlen(temp) - 1;
	write (1, temp, size);
	free (temp);
	return (size);
}
