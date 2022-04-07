/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:07:48 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/07 11:33:57 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	ft_printf("%s", stack);
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	printf("%s\n", "sa");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	printf("%s\n", "sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("%s\n", "ss");
}
