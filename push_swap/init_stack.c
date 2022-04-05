/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:02:29 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/05 16:03:40 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, int argc, char**argv)
{
	int	*node;	
	int	i;

	node = malloc(sizeof(int) * (argc - 1));
	if (!node)
		return ;
	*node = NULL;
	i = 0;
	while (argv[++i])
		node[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (++i > (argc - 1))
		ft_lstadd_back(stack_a, node[i]);
}
