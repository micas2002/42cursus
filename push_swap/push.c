/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:07:59 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/13 12:17:39 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_receiver, t_stack **stack_sender)
{
	t_stack	*node;

	if (!(*stack_receiver))
	{
		node = create_stack((*stack_sender)->data);
		lstadd_back(stack_receiver, node);
	}
	else
	{
		lstadd_front(stack_receiver, stack_sender);
	}
	del_one(stack_sender);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	printf("%s\n", "pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	printf("%s\n", "pb");
}
