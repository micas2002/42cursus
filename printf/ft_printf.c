/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:10 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/26 17:31:48 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	open_format_type(char format_type, va_list args)
{
	int		size;

	if (format_type == 'c')
		size = ft_printf_c(va_arg(args, int));
	else if (format_type == 'd')
		size = ft_printf_d(va_arg(args, int));
	else if (format_type == 'i')
		size = ft_printf_i(va_arg(args, int));
	else if (format_type == 'p')
		size = ft_printf_p(va_arg(args, void *));
	else if (format_type == 's')
		size = ft_printf_s(va_arg(args, char *));
	else if (format_type == 'u')
		size = ft_printf_u(va_arg(args, int));
	else if (format_type == 'x')
		size = ft_printf_x_lower(va_arg(args, int));
	else if (format_type == 'X')
		size = ft_printf_x_upper(va_arg(args, int));
	return (size);
}

int	check_format(char *format, int x)
{
	if (format[x] == 'c' || format[x] == 's' || format[x] == 'p'
		|| format[x] == 'd' || format[x] == 'i' || format[x] == 'u'
		|| format[x] == 'x' || format[x] == 'X')
		return (1);
	return (0);
}

int	treat_format(char *format, int x)
{
	while (format[x] != '\0')
	{
		if (format[x] == '%' && format[x + 1])
		{
			if (format[x + 1] == '%')
			{
				write (1, "%", 1);
				x += 2;
				treat_format(format, x);
			}
			else
			{
				x++;
				break ;
			}		
		}
		ft_putchar_fd(format[x], 1);
		x++;
	}
	return (x);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	int		x;
	char	*temp;
	char	format_type;
	va_list	args;

	if (!format)
		return (-1);
	x = 0;
	size = 0;
	temp = ft_strdup(format);
	va_start(args, format);
	while (temp[x] != '\0')
	{
		x = treat_format(temp, x);
		if (check_format(temp, x) == 1)
		{
			format_type = temp[x];
			size += open_format_type(format_type, args);
		}
		x++;
	}
	va_end(args);
	return (size);
}
