/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:32 by mibernar          #+#    #+#             */
/*   Updated: 2022/07/22 17:37:08 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit (0);
	return (0);
}

int	keys(int key_code)
{
	if (key_code == 65307)
		exit (0);
	else if (key_code == 119 || key_code == 97 || key_code == 115
		|| key_code == 100)
		player_movements(key_code);
	return (0);
}
