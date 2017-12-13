/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:56:36 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/06 15:56:36 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		quit(int key)
{
	exit(key);
}

void	init_mlx(t_env *env)
{
	int	bits;
	int	size;
	int	end;

	env->mlx = mlx_init();
	if (!env->mlx)
		exit(EXIT_FAILURE);
	else
		ft_printf("MLX Serveur loaded.\n");
	env->win = mlx_new_window(env->mlx, F_WIDTH, F_HEIGHT, "Fractol");
	if (!env->win)
		exit(EXIT_FAILURE);
	else
		ft_printf("MLX Window loaded [%d][%d].\n", F_WIDTH, F_HEIGHT);
	env->frame_addr = mlx_new_image(env->mlx, F_WIDTH, F_HEIGHT);
	bits = 24;
	size = 8;
	end = 1;
	env->frame = (int *)mlx_get_data_addr(env->frame_addr, &bits, &size, &end);
	mlx_mouse_hook(env->win, e_mouse_input, env);
	mlx_hook(env->win, 2, (1L << 2), e_key_input, env);
	mlx_hook(env->win, 6, (1L << 6), e_mouse_move, env);
	mlx_hook(env->win, 17, (1L << 17), quit, NULL);
}
