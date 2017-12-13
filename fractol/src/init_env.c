/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:02:41 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/06 16:02:41 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_env(t_env *env)
{
	env->cur = 1;
	env->zoom = 0.75;
	env->h = 0;
	env->v = 0;
	env->max_ite = 1500;
	env->eq = 0;
	env->random = 0;
	env->julia.c_x = -0.539583;
	env->julia.c_y = 0.532407;
	env->quartz.c_x = -0.610937;
	env->quartz.c_y = 0.032407;
	env->julia3.c_x = -0.705208;
	env->julia3.c_y = -0.004630;
	env->box_info = 0;
}
