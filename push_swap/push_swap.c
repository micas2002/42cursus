/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:06 by mibernar          #+#    #+#             */
/*   Updated: 2022/03/30 16:52:39 by mibernar         ###   ########.fr       */
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
		head->data = ft_atoi(argv[position]);
		head = head->next;
		position++;
	}
	return (*head);
}

int	main(int argc, char **argv)
{
	if (error_check(argc, argv) == 0)
	{
		ft_printf("%s\n", "ERROR");
		return (0);
	}
	init_stack(argc, argv);
	return (0);
}
