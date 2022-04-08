/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:02:29 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/08 16:43:01 by mibernar         ###   ########.fr       */
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
		node = create_stack(temp[i]);
		ft_lstadd_back(stack_a, node);
		node = node->next;
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

void	del_one(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = lst;
	lst = temp->next;
	free (temp);
	return ;
}
