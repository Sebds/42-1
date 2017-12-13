/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:47:18 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:11:20 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		check_level(t_env *e)
{
	if (e->map[(int)e->pos_x][(int)e->pos_y] == -2)
	{
		(e->i == 0) ? level_2_splashscreen(e) : 0;
		(e->i == 1) ? level_3_splashscreen(e) : 0;
		(e->i == 2) ? end_splashscreen(e) : 0;
		choose_level(e, ++e->i);
		return (1);
	}
	return (0);
}

void	fps(t_env *e)
{
	struct timeval	start;
	struct timeval	stop;
	double			secs;

	secs = 0;
	gettimeofday(&start, NULL);
	draw(e);
	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) / 1000000;
	secs += (double)(stop.tv_sec - start.tv_sec);
	if (secs < (double)((double)1 / (double)FPS))
		usleep(((double)((double)1 / (double)FPS) - secs) * 1000000);
}

int		handle_keyboard(t_env *e)
{
	double move_speed;
	double rot_speed;

	if (check_level(e))
		return (1);
	move_speed = 0.15;
	rot_speed = 0.1;
	(e->up) ? up(e, move_speed) : 0;
	(e->down) ? down(e, move_speed) : 0;
	(e->left) ? left(e, rot_speed) : 0;
	(e->right) ? right(e, rot_speed) : 0;
	(e->move_left) ? move_left(e, move_speed) : 0;
	(e->move_right) ? move_right(e, move_speed) : 0;
	fps(e);
	return (0);
}
