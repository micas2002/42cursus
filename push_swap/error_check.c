/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:59:19 by mibernar          #+#    #+#             */
/*   Updated: 2022/03/29 12:46:29 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int argc, char **argv, int i)
{
	int	pos;

	pos = 0;
	while (pos <= argc)
	{
		if (ft_strcmp(argv[pos], argv[i]))
			return (0);
		pos++;
	}
	return (1);
}

int	check_int(char **argv, int i)
{
	int	x;

	x = 0;
	if (argv[i][x] == '+' || argv[i][x] == '-')
		x++;
	while (argv[i][x] != '\0')
	{
		if (argv[i][x] > 47 && argv[i][x] < 58)
			return (1);
		x++;
	}
	return (0);
}

int	error_check(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (NULL);
	i = 1;
	while (i <= argc)
	{
		if (check_int(argv, i) == 0)
			return (0);
		else if (check_duplicate(argc, argv, i) == 1)
			return (0);
		i++;
	}
	return (1);
}
