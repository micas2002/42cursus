/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:06 by mibernar          #+#    #+#             */
/*   Updated: 2022/03/29 11:42:40 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int argc, char **argv)
{
	int		position;
	t_stack	*head;

	head = NULL;
	head = (struct stack *)malloc(sizeof(struct stack) * argc);
	position = 1;
	while (position <= argc)
	{
		head->data = argv[position];
		head = head->next;
		position++;
	}
}

int	main(int argc, char **argv)
{
	init_stack(argc, argv);
	return (0);
}
