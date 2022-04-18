/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:06 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/18 15:38:57 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (error_check(argc, argv) == 0)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	init_stack(stack_a, argc, argv);
	sorting(stack_a, stack_b);
	return (0);
}
