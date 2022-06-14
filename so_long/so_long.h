/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/14 13:49:17 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# include "printf/ft_printf.h"

// PROTOTYPES

typedef struct	s_img
{
	void	*reference;
	char	*address;
	void      *pointer;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
}   t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
}t_vars;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		close_window(void);
t_img	new_img(void *mlx, int width, int height);
t_img	new_sprite(void *mlx, char *path);

#endif