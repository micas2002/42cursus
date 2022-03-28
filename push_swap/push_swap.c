/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:06 by mibernar          #+#    #+#             */
/*   Updated: 2022/03/28 12:11:40 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int argc, char **argv)
{
	int				position;
	struct stack	*head;

	head = NULL;
	head = (struct stack *)malloc(sizeof(struct stack) * argc);
	position = 2;
	while (position <= argc)
	{
		head->data = argv[position];
		head->next;
		position++;
	}
}

int	main(int argc, char **argv)
{
	init_stack(argc, argv);
	return (0);
}
