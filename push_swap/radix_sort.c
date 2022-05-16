/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:32:17 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/16 13:51:45 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bigger(t_stack *stack_a)
{
	int	number;

	number = stack_a->data;
	while (stack_a->next)
	{
		if (stack_a->next->data > number)
			number = stack_a->next->data;
		stack_a = stack_a->next;
	}
	return (number);
}

void	radix_sort(t_stack **stack_a)
{
	int	bigger_number;

	bigger_number = get_bigger(*stack_a);
	while ((*stack_a)->next)
	{
		if ((*stack_a)->data == bigger_number)
			break ;
		ra(stack_a);
	}
}
