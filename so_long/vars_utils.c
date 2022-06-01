/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:32 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/01 16:31:45 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int key_code, t_vars *vars)
{
	if (key_code == 27)
		mlx_destroy_window(vars->mlx, vars->window);
	return (0);
}
