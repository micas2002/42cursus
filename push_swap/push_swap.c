/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:06 by mibernar          #+#    #+#             */
/*   Updated: 2022/03/31 14:19:43 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (error_check(argc, argv) == 0)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	stack_a = NULL;
	init_stack(*stack_a, argc, argv);
	return (0);
}
