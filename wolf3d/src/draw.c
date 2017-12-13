/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:52:37 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:11:58 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_draw(t_env *e, int column)
{
	e->camera_x = 2 * column / (double)F_WIDTH - 1;
	e->ray_pos_x = e->pos_x;
	e->ray_pos_y = e->pos_y;
	e->ray_dir_x = e->dir_x + (e->plane_x * e->camera_x);
	e->ray_dir_y = e->dir_y + (e->plane_y * e->camera_x);
	e->map_x = (int)e->ray_pos_x;
	e->map_y = (int)e->ray_pos_y;
	e->delta_dist_x = sqrt(1 + (e->ray_dir_y * e->ray_dir_y) /\
						(e->ray_dir_x * e->ray_dir_x));
	e->delta_dist_y = sqrt(1 + (e->ray_dir_x * e->ray_dir_x) /\
						(e->ray_dir_y * e->ray_dir_y));
}

void	define_wall_height(t_env *e)
{
	int		wall_height;

	if (e->side == 0)
		e->wall_dist = (e->map_x - e->ray_pos_x + (1 - e->step_x) / 2) /\
		e->ray_dir_x;
	else
		e->wall_dist = (e->map_y - e->ray_pos_y + (1 - e->step_y) / 2) /\
		e->ray_dir_y;
	wall_height = (int)(F_HEIGHT / e->wall_dist) * 1;
	e->wall_top = -wall_height / 2 + F_HEIGHT / 2;
	if (e->wall_top < 0)
		e->wall_top = 0;
	e->wall_bottom = wall_height / 2 + F_HEIGHT / 2;
	if (e->wall_bottom >= F_HEIGHT)
		e->wall_bottom = F_HEIGHT - 1;
}

void	define_texture_pixel(t_env *e)
{
	double wall_x;

	e->tx_num = e->map[e->map_x][e->map_y] - 1;
	if (e->side == 0)
		wall_x = e->ray_pos_y + e->wall_dist * e->ray_dir_y;
	else
		wall_x = e->ray_pos_x + e->wall_dist * e->ray_dir_x;
	wall_x -= floor((wall_x));
	e->hit_tx_x = (int)(wall_x * (double)(TEXTURE_W));
	if (e->side == 0 && e->ray_dir_x > 0)
		e->hit_tx_x = TEXTURE_W - e->hit_tx_x - 1;
	if (e->side == 1 && e->ray_dir_y < 0)
		e->hit_tx_x = TEXTURE_W - e->hit_tx_x - 1;
	if (e->tx_num >= 4)
		e->tx_num = 4;
}

int		draw(t_env *e)
{
	int column;

	column = 0;
	while (column < F_WIDTH)
	{
		init_draw(e, column);
		init_ray(e);
		launch_ray(e);
		define_wall_height(e);
		define_texture_pixel(e);
		compute_column(e, column);
		column++;
	}
	if (e->minimap)
		minimap(e);
	mlx_put_image_to_window(e->mlx, e->win, e->frame_addr, 0, 0);
	return (0);
}
