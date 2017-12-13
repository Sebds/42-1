/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:04:54 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:07:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	up(t_env *e, double move_speed)
{
	if (e->map[(int)(e->pos_x + e->dir_x * move_speed)][(int)(e->pos_y)] <= 0)
		e->pos_x += (e->dir_x * move_speed);
	if (e->map[(int)(e->pos_x)][(int)(e->pos_y + e->dir_y * move_speed)] <= 0)
		e->pos_y += (e->dir_y * move_speed);
}

void	down(t_env *e, double move_speed)
{
	if (e->map[(int)(e->pos_x - e->dir_x * move_speed)][(int)(e->pos_y)] <= 0)
		e->pos_x -= e->dir_x * move_speed;
	if (e->map[(int)(e->pos_x)][(int)(e->pos_y - e->dir_y * move_speed)] <= 0)
		e->pos_y -= e->dir_y * move_speed;
}

void	move_left(t_env *e, double move_speed)
{
	if (e->map[(int)(e->pos_x + e->plane_x * move_speed)][(int)(e->pos_y)] <= 0)
		e->pos_x += e->plane_x * (move_speed / 2);
	if (e->map[(int)(e->pos_x)][(int)(e->pos_y + e->plane_y * move_speed)] <= 0)
		e->pos_y += e->plane_y * (move_speed / 2);
}

void	move_right(t_env *e, double move_speed)
{
	if (e->map[(int)(e->pos_x - e->plane_x * move_speed)][(int)(e->pos_y)] <= 0)
		e->pos_x -= e->plane_x * (move_speed / 2);
	if (e->map[(int)(e->pos_x)][(int)(e->pos_y - e->plane_y * move_speed)] <= 0)
		e->pos_y -= e->plane_y * (move_speed / 2);
}
