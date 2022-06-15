/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:32 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/15 10:15:55 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit (1);
	return (0);
}

void	close_game(void *mlx_win)
{
	t_vars	vars;

	mlx_hook(mlx_win, 2, (1L << 2), close_window, &vars);
	mlx_hook(mlx_win, 17, (1L << 17), close_window, &vars);
}
