/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:16:00 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:18:20 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*g_tx[TEXTURE_NUMBER] =
{
	"textures/wall_1.xpm",
	"textures/wall_2.xpm",
	"textures/wall_3.xpm",
	"textures/wall_4.xpm",
	"textures/wall_5.xpm"
};

char	*g_level[3] =
{
	"levels/map_1.w3d",
	"levels/map_2.w3d",
	"levels/map_3.w3d"
};

int		wolf_exit(int key)
{
	exit(key);
}

void	choose_level(t_env *e, int i)
{
	e->map = e->level_map[i];
	e->map_w = e->level_map_w[i];
	e->map_h = e->level_map_h[i];
	e->pos_x = e->level_pos_x[i];
	e->pos_y = e->level_pos_y[i];
}

int		main(void)
{
	t_env *e;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	init_env(e);
	load_all_levels(e);
	choose_level(e, 0);
	e->i = 0;
	init_mlx(e);
	start_splashscreen(e);
	level_1_splashscreen(e);
	mlx_loop_hook(e->mlx, handle_keyboard, e);
	mlx_loop(e->mlx);
}
