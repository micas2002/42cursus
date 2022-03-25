/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:06 by mibernar          #+#    #+#             */
/*   Updated: 2022/03/25 17:52:14 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(int argc, char **argv)
{
	int		top;
	int		i;
	char	**stack_a;
	char	**stack_b;

	top = -1;
	i = 1;
	stack_a = malloc(sizeof(char *) * argc);
	while (top <= (argc))
	{
		top = top + 1;
		stack_a[top] = argv[i];
		top++;
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	init_stack(argc, argv);
	return (0);
}
