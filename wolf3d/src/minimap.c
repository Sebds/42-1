/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:01:06 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:07:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fill_minimap(t_env *e, int i, int j)
{
	if ((int)e->pos_x == e->scale_y && (int)e->pos_y == e->scale_x)
		e->frame_array[50 + i][50 + j] = 0x000000;
	else if (e->map[e->scale_y][e->scale_x] == 0)
		e->frame_array[50 + i][50 + j] = 0x626262;
	else if (e->map[e->scale_y][e->scale_x] == 1)
		e->frame_array[50 + i][50 + j] = 0xFF0000;
	else if (e->map[e->scale_y][e->scale_x] == 2)
		e->frame_array[50 + i][50 + j] = 0xFFFF00;
	else if (e->map[e->scale_y][e->scale_x] == 3)
		e->frame_array[50 + i][50 + j] = 0x00FFFF;
	else if (e->map[e->scale_y][e->scale_x] == 4)
		e->frame_array[50 + i][50 + j] = 0x0000FF;
	else if (e->map[e->scale_y][e->scale_x] >= 5)
		e->frame_array[50 + i][50 + j] = 0x6F0F0F;
	else
		e->frame_array[50 + i][50 + j] = 0xFFFFFF;
}

void	minimap(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < 10 * e->map_h)
	{
		j = 0;
		while (j < 10 * e->map_w)
		{
			e->scale_y = (e->map_h * i) / (10 * e->map_h);
			e->scale_x = (e->map_w * j) / (10 * e->map_w);
			fill_minimap(e, i, j);
			j++;
		}
		i++;
	}
}
