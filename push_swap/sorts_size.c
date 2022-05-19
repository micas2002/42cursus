/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:40:42 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/19 16:15:55 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
		{
			if ((*stack_a)->data > (*stack_a)->next->next->data)
				ra(stack_a);
			else
				sa(stack_a);
		}
	}
	else if ((*stack_a)->data < (*stack_a)->next->data)
	{
		if ((*stack_a)->data > (*stack_a)->next->next->data)
			rra(stack_a);
		else if ((*stack_a)->next->data > ((*stack_a)->next->next->data))
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		if ((*stack_a)->data > (*stack_a)->next->next->data)
		{
			if ((*stack_a)->data > (*stack_a)->next->next->next->data)
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

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		if ((*stack_a)->data > (*stack_a)->next->next->data)
		{
			if ((*stack_a)->data > (*stack_a)->next->next->next->data)
			{
				if ((*stack_a)->data > (*stack_a)->next->next->next->next->data)
				{
					ra(stack_a);
					return ;
				}
				rra(stack_a);
				sa(stack_a);
				ra(stack_a);
				ra(stack_a);
			}
			pb(stack_a, stack_b);
			ra(stack_a);
			ra(stack_a);
			pb(stack_a, stack_b);
			rra(stack_a);
			rra(stack_a);
		}
		sa(stack_a);
	}
}
