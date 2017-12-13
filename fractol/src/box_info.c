/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:56:53 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/08 22:06:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	box_info(t_env *env)
{
	if (env->display_box == 0)
		env->box_info = mlx_new_window(env->mlx, 350, 175, "Fractol Infos");
	else
		mlx_destroy_window(env->mlx, env->box_info);
	env->display_box = !env->display_box;
}

void	display_name(t_env *env)
{
	char s[50];

	if (env->cur == 1)
		sprintf(s, "             Julia");
	if (env->cur == 2)
		sprintf(s, "             Mandelbrot");
	if (env->cur == 3)
		sprintf(s, "             Burnship");
	if (env->cur == 4)
		sprintf(s, "             Quartz");
	if (env->cur == 5)
		sprintf(s, "             Julia Cube");
	mlx_string_put(env->mlx, env->box_info, 15, 10, 0xFF0000, s);
}

void	display_spec_info(t_env *env)
{
	char s[50];

	if (env->cur == 1)
	{
		sprintf(s, "C_x           : %f", env->julia.c_x);
		mlx_string_put(env->mlx, env->box_info, 15, 115, 0xFFFFFF, s);
		sprintf(s, "C_y           : %f", env->julia.c_y);
	}
	if (env->cur == 4)
	{
		sprintf(s, "C_x           : %f", env->quartz.c_x);
		mlx_string_put(env->mlx, env->box_info, 15, 115, 0xFFFFFF, s);
		sprintf(s, "C_y           : %f", env->quartz.c_y);
	}
	if (env->cur == 5)
	{
		sprintf(s, "C_x           : %f", env->julia3.c_x);
		mlx_string_put(env->mlx, env->box_info, 15, 115, 0xFFFFFF, s);
		sprintf(s, "C_y           : %f", env->julia3.c_y);
	}
	if (env->cur == 1 || env->cur == 4 || env->cur == 5)
		mlx_string_put(env->mlx, env->box_info, 15, 135, 0xFFFFFF, s);
}

void	update_box_info(t_env *env)
{
	char s[50];

	if (!env->display_box)
		return ;
	mlx_clear_window(env->mlx, env->box_info);
	display_name(env);
	sprintf(s, "Iteration max : %.0f", env->max_ite);
	mlx_string_put(env->mlx, env->box_info, 15, 35, 0xFFFFFF, s);
	sprintf(s, "Zoom          : %.0f", env->zoom);
	mlx_string_put(env->mlx, env->box_info, 15, 55, 0xFFFFFF, s);
	sprintf(s, "H trans       : %f", env->h);
	mlx_string_put(env->mlx, env->box_info, 15, 75, 0xFFFFFF, s);
	sprintf(s, "V trans       : %f", env->v);
	mlx_string_put(env->mlx, env->box_info, 15, 95, 0xFFFFFF, s);
	display_spec_info(env);
}
