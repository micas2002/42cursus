/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:40:42 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/28 11:40:22 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->data > stack->next->next->data)
		ra(&stack);
	if (stack->data > stack->next->data)
		sa(&stack);
	if (stack->next->data > stack->next->next->data)
	{
		rra(&stack);
		sa(&stack);
	}
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	pb(&stack_a, &stack_b);
	sort_3(stack_a);
	pa(&stack_a, &stack_b);
	if (stack_a->data > stack_a->next->data)
	{
		if (stack_a->data > stack_a->next->next->data)
		{
			if (stack_a->data > stack_a->next->next->next->data)
			{
				ra(&stack_a);
				return ;
			}
			rra(&stack_a);
			sa(&stack_a);
			ra(&stack_a);
			return ;
		}
		sa(&stack_a);
	}
}
