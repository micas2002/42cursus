/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:40:42 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/19 16:09:27 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	if (stack[0] > stack[2])
		ra(stack);
	if (stack[0] > stack[1])
		sa(stack);
	if (stack[1] > stack[2])
	{
		rra(stack);
		sa(stack);
	}
}

void	sort_4(t_stack **stack)
{
	
}
