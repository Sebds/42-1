/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/06 21:38:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_reset_frame(t_env *info)
{
	int i;

	i = -1;
	while (++i < info->width * info->height)
		info->frame[i] = 0x000000;
}

void	ft_init_split_frame(t_env *info)
{
	int i;

	info->split_frame = (int **)malloc(sizeof(int *) * info->height);
	i = -1;
	while (++i < info->height)
		info->split_frame[i] = &info->frame[i * info->width];
	i = -1;
	while (++i < info->width * 60)
	{
		if (i < info->width)
			info->black[i] = 0xFFFFFF;
		else
			info->black[i] = 0x222222;
	}
}

void	ft_init_frame(t_env *info)
{
	int *bits;
	int	*size;
	int	*end;

	bits = (int *)(malloc(sizeof(int) * 1));
	bits[0] = 24;
	size = (int *)(malloc(sizeof(int) * 1));
	size[0] = 8 * info->width_scale;
	end = (int *)(malloc(sizeof(int) * 1));
	end[0] = 1;
	info->black_addr = mlx_new_image(info->mlx, info->width, 60);
	info->black = (int *)mlx_get_data_addr(info->black_addr, bits, size, end);
	info->frame_addr = mlx_new_image(info->mlx, info->width, info->height);
	info->frame = (int *)mlx_get_data_addr(info->frame_addr, bits, size, end);
	ft_init_split_frame(info);
	free(bits);
	free(size);
	free(end);
}

void	ft_scale(t_env *info)
{
	info->height = MAX_WIN_HEIGHT;
	info->height_scale = info->height / info->b_line;
	info->width = info->b_col * info->height_scale;
	info->width_scale = info->width / info->b_col;
	if (info->width_scale == 0 || info->height_scale == 0)
		ft_quit("Please increase win size", info);
}

void	ft_init_visualizer(t_env *info)
{
	int		x;
	int		y;

	ft_scale(info);
	if (ENABLE_VISUALIZER)
	{
		info->mlx = mlx_init();
		if (info->mlx == NULL)
			ft_quit("Could not init mlx.\n", info);
		x = info->width;
		y = info->height + 60;
		info->win = mlx_new_window(info->mlx, x, y, "Filler Visualizer");
		if (info->win == NULL)
			ft_quit("Could not create windows.\n", info);
		mlx_key_hook(info->win, ft_close_win, info);
		ft_init_frame(info);
	}
	info->init_mlx = 1;
}
