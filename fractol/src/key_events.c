/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:08:21 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/06 16:08:21 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	simple_key_input(int key, t_env *env)
{
	(key == 53) ? exit(0) : 0;
	(key == 13) ? env->zoom *= ZOOM_INCREMENTATON : 0;
	(key == 01) ? env->zoom /= ZOOM_INCREMENTATON : 0;
	(key == 126) ? env->v -= 1 / (4 * env->zoom) : 0;
	(key == 124) ? env->h += 1 / (4 * env->zoom) : 0;
	(key == 125) ? env->v += 1 / (4 * env->zoom) : 0;
	(key == 123) ? env->h -= 1 / (4 * env->zoom) : 0;
	(key == 11) ? env->random = 0 : 0;
	(key == 35) ? env->eq = !env->eq : 0;
	(key == 18) ? env->cur = 1 : 0;
	(key == 19) ? env->cur = 2 : 0;
	(key == 20) ? env->cur = 3 : 0;
	(key == 21) ? env->cur = 4 : 0;
	(key == 23) ? env->cur = 5 : 0;
	(key == 34) ? box_info(env) : 0;
	(env->zoom < 0.5) ? env->zoom = 0.5 : 0;
}

int		e_key_input(int key, t_env *env)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	srand((unsigned int)t1.tv_usec * (unsigned int)t1.tv_sec);
	if (key == 15 || (key >= 18 && key <= 21))
	{
		env->zoom = 0.75;
		env->h = 0;
		env->v = 0;
		env->max_ite = ITE_MAX_DEFAULT;
	}
	if (env->zoom >= 0.75)
	{
		(key == 24 || key == 13) ? env->max_ite += ITE_INCREMENTATION : 0;
		(key == 27 || key == 01) ? env->max_ite -= ITE_INCREMENTATION : 0;
	}
	if (key == 8)
	{
		env->random = rand();
		env->random %= 20;
		(env->random == 0) ? env->random++ : 0;
	}
	simple_key_input(key, env);
	compute(env);
	return (key);
}
