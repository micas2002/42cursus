/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:02:29 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/26 15:09:27 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_one(t_stack	*stack)
{
	
}

t_stack	*lstlast(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*lstadd_back(t_stack *stack, t_stack *node)
{
	t_stack	*last;

	if (stack)
	{
		last = lstlast(stack);
		last->next = node;
		node->previous = last;
	}
	else
		stack = node;
	return (stack);
}

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
		temp_stack = lstadd_back(temp_stack, node);
	}
	return (temp_stack);
}