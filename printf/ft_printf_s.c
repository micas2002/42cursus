/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:50:08 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/10 17:18:22 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_printf_s(char *args)
{
	char	*str;
	int		x;
	int		size;

	size = ft_strlen(args);
	str = malloc(sizeof(char) * si)
	x = 0;
	while (args[x] != '\0')
	{
		str[x] = args[x];
		x++;
	}
	str[x] = args[x];
	return (str);
}
