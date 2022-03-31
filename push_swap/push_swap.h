/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:10:55 by mibernar          #+#    #+#             */
/*   Updated: 2022/03/31 13:30:16 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

// PROTOTYPES

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}t_stack;

int		error_check(int argc, char **argv);
void	init_stack(t_stack stack_a, int argc, char**argv);

#endif