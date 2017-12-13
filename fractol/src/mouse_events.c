/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 01:42:34 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/03 01:42:34 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		e_mouse_input(int clic, int x, int y, t_env *env)
{
	if (x <= 0 || y <= 0)
		return (0);
	x -= F_WIDTH / 2;
	y -= F_HEIGHT / 2;
	if (clic == LEFT_CLIC || clic == SCROLL_UP)
	{
		env->max_ite += ITE_INCREMENTATION;
		env->zoom *= ZOOM_INCREMENTATON;
		env->v += y / (400 * env->zoom);
		env->h += x / (400 * env->zoom);
	}
	else if (clic == RIGHT_CLIC || clic == SCROLL_DOWN)
	{
		if (env->zoom > 1)
		{
			env->max_ite -= ITE_INCREMENTATION;
			env->zoom /= ZOOM_INCREMENTATON;
		}
		env->v -= y / (400 * env->zoom);
		env->h -= x / (400 * env->zoom);
	}
	compute(env);
	return (1);
}

int		e_mouse_move(int x, int y, t_env *env)
{
	x -= F_WIDTH / 2;
	y -= F_HEIGHT / 2;
	if (env->eq == 1 && env->cur == 1)
	{
		env->julia.c_x = x / (float)F_WIDTH;
		env->julia.c_y = y / (float)F_HEIGHT;
		compute(env);
	}
	if (env->eq == 1 && env->cur == 4)
	{
		env->quartz.c_x = x / (float)F_WIDTH;
		env->quartz.c_y = y / (float)F_HEIGHT;
		compute(env);
	}
	if (env->eq == 1 && env->cur == 5)
	{
		env->julia3.c_x = x / (float)F_WIDTH;
		env->julia3.c_y = y / (float)F_HEIGHT;
		compute(env);
	}
	return (0);
}
