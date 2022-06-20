/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:32 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/20 15:27:56 by miguel           ###   ########.fr       */
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
	t_mlx	vars;

	mlx_hook(mlx_win, 2, (1L << 0), close_window, &vars);
	mlx_hook(mlx_win, 17, (1L << 17), close_window, &vars);
}