/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:07:59 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/26 14:55:20 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_receiver, t_stack *stack_sender)
{
	if (!stack_receiver)
		stack_receiver->data = stack_sender->data;
	else
	{
		stack_receiver->next->data = stack_receiver->data;
		stack_receiver->data = stack_sender->data;
	}
	del_one(stack_sender);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	printf("%s\n", "pa");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	printf("%s\n", "pb");
}
