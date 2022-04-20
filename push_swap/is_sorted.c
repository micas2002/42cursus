/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:27:12 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/20 15:38:32 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	int	temp;
	int	x;

	x = -1;
	while (stack[++x])
	{
		if (stack[x] > stack [x + 1])
			return (0);
	}
	return (1);
}
