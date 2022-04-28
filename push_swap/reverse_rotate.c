/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:08:27 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/28 12:37:28 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	int	temp;

	temp = (*stack)->data;
	while (stack && (*stack)->next != NULL)
	{
		(*stack)->data = (*stack)->next->data;
		*stack = (*stack)->next;
	}
	(*stack)->data = temp;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	printf("%s\n", "rra");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	printf("%s\n", "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	printf("%s\n", "rrr");
}
