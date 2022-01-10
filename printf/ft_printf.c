/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:10 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/10 18:00:45 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char *format, int x)
{
	if (format[x] == "c" || format[x] == "s" || format[x] == "p"
		|| format[x] == "d" || format[x] == "i" || format[x] == "u"
		|| format[x] == "x" || format[x] == "X" || format[x] == "%")
		return (1);
	else
		return (0);
}

int	count_size(char *format, va_list args)
{
	int	size;
	int	x;

	x = 0;
	size = 0;
	if (!format)
		return (-1);
	while (format)
	{
		if (format[x] == '%' && format[x + 1])
			x++;
		else if (check_format(format, x) == 1)
		{
			
		}
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		arg_size;
	va_list	args;

	arg_size = 0;
	va_start(args, format);
	count_size(format, args);
	va_end(args);
}

int	main(void)
{
	ft_printf("%c", 'a');
	return (0);
}
