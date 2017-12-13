/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:52:53 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:07:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_env(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->pos_y = -1.5;
	e->pos_x = -1.5;
	e->dir_x = -1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 1.5;
	e->sky_shift = 0;
	e->up = 0;
	e->down = 0;
	e->left = 0;
	e->right = 0;
	e->minimap = 0;
}
