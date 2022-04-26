/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:08:09 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/26 14:27:11 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	temp;


	stack = lstlast(stack);
	temp = stack->data;
	while (stack->previous != NULL)
	{
		stack->data = stack->previous->data;
		stack = stack->previous;
	}
	stack->data = temp;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	printf("%s\n", "ra");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	printf("%s\n", "rb");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("%s\n", "rr");
}
