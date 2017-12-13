/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:07:11 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:11:13 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	left(t_env *e, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	e->sky_shift++;
	old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(-rot_speed) - e->dir_y * sin(-rot_speed);
	e->dir_y = old_dir_x * sin(-rot_speed) + e->dir_y * cos(-rot_speed);
	old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(-rot_speed) - e->plane_y * sin(-rot_speed);
	e->plane_y = old_plane_x * sin(-rot_speed) + e->plane_y * cos(-rot_speed);
}

void	right(t_env *e, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	e->sky_shift--;
	old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(rot_speed) - e->dir_y * sin(rot_speed);
	e->dir_y = old_dir_x * sin(rot_speed) + e->dir_y * cos(rot_speed);
	old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(rot_speed) - e->plane_y * sin(rot_speed);
	e->plane_y = old_plane_x * sin(rot_speed) + e->plane_y * cos(rot_speed);
}
