/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:10 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/14 15:49:51 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	open_format_type(char format_type, va_list args)
{
	int		size;

	if (format_type == 'c')
		size = ft_printf_c(args);
	else if (format_type == 'd')
		size = ft_printf_d(args);
	else if (format_type == 'i')
		size = ft_printf_i(args);
	else if (format_type == 'p')
		size = ft_printf_p(args);
	else if (format_type == '%')
		size = ft_printf_percent(args);
	else if (format_type == 's')
		size = ft_printf_s(args);
	else if (format_type == 'u')
		size = ft_printf_u(args);
	else if (format_type == 'x')
		size = ft_printf_x_lower(args);
	else if (format_type == 'X')
		size = ft_printf_x_upper(args);
	return (size);
}

int	check_format(char *format, int x)
{
	if (format[x] == 'c' || format[x] == 's' || format[x] == 'p'
		|| format[x] == 'd' || format[x] == 'i' || format[x] == 'u'
		|| format[x] == 'x' || format[x] == 'X' || format[x] == '%')
		return (1);
	return (0);
}

int	treat_format(char *format, int x)
{
	while (format)
	{
		if (format[x] == '%' && format[x + 1])
		{
			x++;
			break ;
		}
		ft_putchar_fd(format[x], 1);
		x++;
	}
	return (x);
}

int	count_size(char *format, va_list args)
{
	int		size;
	int		x;
	char	format_type;

	x = 0;
	size = 0;
	while (format)
	{
		x = treat_format(format, x);
		if (check_format(format, x) == 1)
		{
			format_type = format[x];
			size += open_format_type(format_type, args);
		}
		x++;
		args++;
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		arg_size;
	char	*temp;
	va_list	args;

	if (!format)
		return (-1);
	temp = ft_strdup(format);
	va_start(args, format);
	arg_size = count_size(temp, args);
	va_end(args);
	return (arg_size);
}

int	main(void)
{
	ft_printf("%c", 'a');
	return (0);
}
