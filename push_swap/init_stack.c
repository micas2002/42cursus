/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:02:29 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/19 12:29:09 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (stack)
	{
		if (*stack)
		{
			last = lstlast(*stack);
			last->next = node;
		}
		else
			*stack = node;
	}
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
	head = temp;
	return (head);
}

void	del_one(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	temp = lst[0];
	lst[0] = temp->next;
	free (temp);
	return ;
}

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
		node = create_stack(temp[i]);
		lstadd_back(stack_a, node);
		node = node->next;
	}
}
