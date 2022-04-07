/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:02:29 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/07 12:21:39 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, int argc, char **argv)
{
	t_stack	*node;
	int		*temp;
	int		i;

	temp = malloc(sizeof(int) * (argc - 1));
	if (!temp)
		return ;
	i = 0;
	while (argv[++i])
		temp[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (++i < (argc - 1))
	{
		node = temp[i];
		ft_lstadd_back(stack_a, node);
		node = node->next;
	}
}
