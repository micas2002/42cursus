/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:07:48 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/26 14:02:53 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	printf("%s\n", "sa");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	printf("%s\n", "sb");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("%s\n", "ss");
}
