/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:53:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:19:26 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_skybox(t_env *e, int i)
{
	int width;
	int height;
	int bits;
	int size;
	int end;

	width = SKYBOX_W;
	height = SKYBOX_H;
	e->sky_addr = mlx_xpm_file_to_image(e->mlx, SKYBOX, &width, &height);
	e->sky = (int *)mlx_get_data_addr(e->sky_addr, &bits, &size, &end);
	e->sky_array = (int **)ft_memalloc(sizeof(int *) * (height + 1));
	i = -1;
	while (++i < height)
		e->sky_array[i] = &e->sky[i * width];
}

void	load_texture(t_env *e, int i, int j)
{
	int tx_w;
	int tx_h;
	int bits;
	int size;
	int end;

	tx_w = TEXTURE_W;
	tx_h = TEXTURE_H;
	while (i < TEXTURE_NUMBER)
	{
		e->tx_addr[i] = mlx_xpm_file_to_image(e->mlx, g_tx[i], &tx_w, &tx_h);
		e->tx[i] = (int *)mlx_get_data_addr(e->tx_addr[i], &bits, &size, &end);
		e->tx_array[i] = (int **)ft_memalloc(sizeof(int *) * (tx_h + 1));
		j = -1;
		while (++j < tx_h)
			e->tx_array[i][j] = &e->tx[i][j * tx_w];
		i++;
	}
	load_skybox(e, 0);
}

int		start_move(int key, t_env *e)
{
	(key == 13) ? e->up = 1 : 0;
	(key == 1) ? e->down = 1 : 0;
	(key == 124) ? e->left = 1 : 0;
	(key == 123) ? e->right = 1 : 0;
	(key == 2) ? e->move_left = 1 : 0;
	(key == 0) ? e->move_right = 1 : 0;
	(key == 8) ? e->minimap = 1 : 0;
	(key == 53) ? exit(1) : 0;
	return (1);
}

int		stop_move(int key, t_env *e)
{
	(key == 13) ? e->up = 0 : 0;
	(key == 1) ? e->down = 0 : 0;
	(key == 124) ? e->left = 0 : 0;
	(key == 123) ? e->right = 0 : 0;
	(key == 2) ? e->move_left = 0 : 0;
	(key == 0) ? e->move_right = 0 : 0;
	(key == 8) ? e->minimap = 0 : 0;
	return (1);
}

void	init_mlx(t_env *e)
{
	int	bits;
	int	size;
	int	end;
	int i;

	if (!(e->mlx = mlx_init()))
		exit(1);
	mlx_do_key_autorepeaton(e->mlx);
	if (!(e->win = mlx_new_window(e->mlx, F_WIDTH, F_HEIGHT, "Wolf3D")))
		exit(1);
	e->frame_addr = mlx_new_image(e->mlx, F_WIDTH, F_HEIGHT);
	e->frame = (int *)mlx_get_data_addr(e->frame_addr, &bits, &size, &end);
	e->frame_array = (int **)ft_memalloc(sizeof(int *) * F_HEIGHT);
	i = -1;
	while (++i < (int)F_HEIGHT)
		e->frame_array[i] = &e->frame[i * (int)F_WIDTH];
	mlx_do_key_autorepeaton(e->mlx);
	mlx_hook(e->win, 2, (1L << 0), start_move, e);
	mlx_hook(e->win, 3, (1L << 1), stop_move, e);
	mlx_hook(e->win, 17, (1L << 2), wolf_exit, NULL);
	load_texture(e, 0, 0);
}
