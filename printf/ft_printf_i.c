/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:05:12 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/10 13:08:18 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_printf_i(int args)
{
	char	*str;

	str = ft_itoa(int args);
	return (str);
}
