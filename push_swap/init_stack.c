/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:02:29 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/13 11:28:24 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int data)
{
	t_stack	*head;
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	head = NULL;
	temp->data = data;
	temp->next = NULL;
	temp->previous = NULL;
	head = temp;
	return (head);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*node;
	t_stack	*temp_stack;
	int		*temp;
	int		i;

	temp = malloc(sizeof(int) * (argc));
	if (!temp)
		return (NULL);
	i = 0;
	while (argv[++i])
		temp[i - 1] = ft_atoi(argv[i]);
	temp_stack = NULL;
	i = -1;
	while (++i < (argc - 1))
	{
		node = create_stack(temp[i]);
		lstadd_back(&temp_stack, node);
	}
	return (temp_stack);
}
