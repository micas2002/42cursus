/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:32 by mibernar          #+#    #+#             */
/*   Updated: 2022/07/28 12:14:24 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit (0);
	return (0);
}

int	keys(int key_code, t_game *mlx)
{
	if (key_code == 65307)
		exit (0);
	else if (key_code == 119 || key_code == 97 || key_code == 115
		|| key_code == 100)
		player_movements(key_code, mlx);
	return (0);
}
