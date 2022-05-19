/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:06 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/19 10:53:47 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack *stack)
// {
// 	t_stack	*temp;

// 	temp = stack;
// 	while (temp != NULL)
// 	{
// 		printf("%d\n", temp->data);
// 		temp = temp->next;
// 	}
// }

void	sorting(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	stack_size;

	stack_size = (argc - 1);
	if (is_sorted(stack_a) == 1)
		return ;
	if (stack_size == 2)
		sa(&stack_a);
	else if (stack_size == 3)
		sort_3(&stack_a);
	else if (stack_size == 4)
		sort_4(&stack_a, &stack_b);
	else if (stack_size == 5)
		sort_5(&stack_a, &stack_b);
	else
	{
		insertion_sort(stack_a, stack_b, argc);
		while (stack_b)
			pb (&stack_a, &stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (error_check(argc, argv) == 1)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(argc, argv);
	sorting(stack_a, stack_b, argc);
//	print_stack(stack_a);
	return (0);
}
