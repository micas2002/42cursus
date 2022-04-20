/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:40:42 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/20 15:21:37 by mibernar         ###   ########.fr       */
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

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if (stack_a[0] > stack_a[1])
	{
		if (stack_a[0] > stack_a[2])
		{
			if (stack_a[0] > stack_a[3])
			{
				ra(stack_a);
				return ;
			}
			rra(stack_a);
			sa(stack_a);
			ra(stack_a);
			return ;
		}
		sa(stack_a);
	}
}
