/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:07:59 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/19 14:47:34 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*element;

	element = new;
	element->next = *lst;
	*lst = element;
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*temp;

	temp = NULL;
	if (!stack_2)
		return ;
	temp = create_stack((*stack_2)->data);
	lstadd_front(stack_1, temp);
	del_one(stack_2);
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
