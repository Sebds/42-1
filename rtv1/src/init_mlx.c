/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:40:55 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		keyboard(int key)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void	init_mlx(t_env *e)
{
	int	bits;
	int	size;
	int	end;
	int i;

	if (!(e->mlx = mlx_init()))
		quit("Unable to start mlx server.");
	if (!(e->win = mlx_new_window(e->mlx, F_WIDTH, F_HEIGHT, "RTv1")))
		quit("Unable to start mlx window.");
	if (!(e->frame_addr = mlx_new_image(e->mlx, F_WIDTH, F_HEIGHT)))
		quit("Unable to get mlx new image.");
	e->frame = (int *)mlx_get_data_addr(e->frame_addr, &bits, &size, &end);
	e->frame_array = (int **)ft_memalloc(sizeof(int *) * F_HEIGHT);
	i = -1;
	while (++i < (int)F_HEIGHT)
		e->frame_array[i] = &e->frame[i * (int)F_WIDTH];
	mlx_hook(e->win, 2, (1L << 0), keyboard, NULL);
	mlx_hook(e->win, 17, (1L << 0), (void *)quit, NULL);
}
