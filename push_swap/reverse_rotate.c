/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:08:27 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/18 14:58:58 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	int		x;

	x = 0;
	while (stack[x])
		x++;
	temp = stack[x];
	while (x >= 0)
	{
		stack[x] = stack[x - 1];
		x--;
	}
	stack[x] = temp;
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
