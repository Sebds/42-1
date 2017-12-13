/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:34:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:07:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	start_splashscreen(t_env *e)
{
	int height;

	mlx_clear_window(e->mlx, e->win);
	height = F_HEIGHT / 2;
	mlx_string_put(e->mlx, e->win, F_WIDTH / 3, height, 0xFFFFFF, START);
	height = F_HEIGHT / 2 + 20;
	mlx_string_put(e->mlx, e->win, F_WIDTH / 3, height, 0xFF0000, START2);
	mlx_do_sync(e->mlx);
	sleep(4);
}

void	end_splashscreen(t_env *e)
{
	int height;

	mlx_clear_window(e->mlx, e->win);
	height = F_HEIGHT / 2;
	mlx_string_put(e->mlx, e->win, F_WIDTH / 2, height, 0x00FF00, END);
	height = F_HEIGHT / 2 + 20;
	mlx_string_put(e->mlx, e->win, F_WIDTH / 2, height, 0xFFFFFF, END_2);
	height = F_HEIGHT / 2 + 40;
	mlx_string_put(e->mlx, e->win, F_WIDTH / 2, height, 0xFFFFFF, END_3);
	mlx_do_sync(e->mlx);
	sleep(4);
	exit(0);
}

void	level_1_splashscreen(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, F_WIDTH / 2, F_HEIGHT / 2, 0xFF0000, LVL1);
	mlx_do_sync(e->mlx);
	sleep(2);
}

void	level_2_splashscreen(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, F_WIDTH / 2, F_HEIGHT / 2, 0xFF0000, LVL2);
	mlx_do_sync(e->mlx);
	sleep(2);
}

void	level_3_splashscreen(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, F_WIDTH / 2, F_HEIGHT / 2, 0xFF0000, LVL3);
	mlx_do_sync(e->mlx);
	sleep(2);
}
