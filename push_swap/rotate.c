/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:08:09 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/25 11:43:08 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{

}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	printf("%s\n", "ra");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	printf("%s\n", "rb");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("%s\n", "rr");
}
