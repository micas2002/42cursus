/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:34:58 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/19 11:10:03 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_stack *stack_a, int lowest_num)
{
	int	x;

	x = 0;
	while (stack_a->next)
	{	
		if (stack_a->data == lowest_num)
			break ;
		x++;
	}
	return (x);
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	lowest_num;
	int	pos;
	t_stack	*temp;

	if (!stack_a)
		return ;
	temp = stack_a;
	lowest_num = stack_a->data;
	while (temp->next)
	{
		if (temp->data < lowest_num)
			lowest_num = temp->data;
		temp = temp->next;
	}
	pos = get_pos(stack_a, lowest_num);
	if (pos <= (argc - 1) / 2)
	{
		while (stack_a->data != lowest_num)
			ra(&stack_a);
	}
	else
		while (stack_a->data != lowest_num)
			rra(&stack_a);
	pa(&stack_a, &stack_b);
	insertion_sort(stack_a, stack_b, argc);
}
