/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:08:09 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/18 14:52:44 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	int		x;

	temp = stack[0];
	x = -1;
	while (stack[++x])
		stack[x] = stack[x + 1]; 
	stack[x] = temp;
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
