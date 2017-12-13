/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_compute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:51:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:07:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_sky(t_env *e, int line, int column)
{
	int sky_col;

	sky_col = column + SKY_SHIFT_COEF * e->sky_shift;
	if (sky_col < 0)
	{
		sky_col %= (int)SKYBOX_W - 1;
		sky_col = abs(sky_col);
	}
	if (sky_col > SKYBOX_W - 1)
		sky_col %= (int)SKYBOX_W - 1;
	e->frame_array[line][column] = e->sky_array[line][sky_col];
}

void	draw_wall(t_env *e, int line, int column)
{
	int line_height;
	int tx;
	int d;

	line_height = (F_HEIGHT / e->wall_dist);
	d = line * 256 - F_HEIGHT * 128 + line_height * 128;
	e->hit_tx_y = ((d * TEXTURE_H) / line_height) / 256;
	(e->hit_tx_y >= 255) ? e->hit_tx_y %= 255 : 0;
	(e->hit_tx_x >= 255) ? e->hit_tx_x %= 255 : 0;
	(e->hit_tx_x < 0) ? e->hit_tx_x = 0 : 0;
	(e->hit_tx_y < 0) ? e->hit_tx_y = 0 : 0;
	tx = e->tx_num;
	e->frame_array[line][column] = e->tx_array[tx][e->hit_tx_y][e->hit_tx_x];
}

void	draw_floor(t_env *e, int line, int column)
{
	e->frame_array[line][column] = FLOOR_COLOR;
}

void	compute_column(t_env *e, int column)
{
	int line;

	line = 0;
	while (line < F_HEIGHT)
	{
		if (line < e->wall_top)
			draw_sky(e, line, column);
		else if (line >= e->wall_top && line < e->wall_bottom)
			draw_wall(e, line, column);
		else
			draw_floor(e, line, column);
		line++;
	}
}
