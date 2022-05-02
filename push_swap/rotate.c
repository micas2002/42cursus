/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:08:09 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/02 11:54:57 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = (*stack)->next;
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	temp->next = NULL;
	(*stack)->next = temp;
	*stack = temp2;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	printf("%s\n", "ra");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	printf("%s\n", "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("%s\n", "rr");
}
