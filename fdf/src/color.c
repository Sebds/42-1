/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:31:50 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/26 22:31:50 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_write_buffer_color(t_fdf *fdf, int x, int y, float z)
{
	float	color;
	float	base;

	(z == 0 && !fdf->white_flat) ? (z = 1) : 0;
	if (fdf->alt_max == 0 || z == 0 || fdf->no_color)
	{
		fdf->split_frame[y][x] = 0xFFFFFF;
		return ;
	}
	if (fabsf((z * 100 / fdf->alt_max)) >= 66.00)
		base = 0xFF0000;
	else if (fabsf((z * 100 / fdf->alt_max)) >= 33.00)
		base = 0x00FF00;
	else
		base = 0x0000FF;
	color = (fabsf((z * 10000) / fdf->alt_max) * 6.5555);
	fdf->split_frame[y][x] = base + color;
}

int		ft_get_color_between_coord(t_fdf *fdf, int n, int v_case)
{
	if (v_case == 1)
	{
		if (labs(fdf->cur_x - n) <= labs(fdf->next_x - n))
			return (fdf->cur_z);
		else
			return (fdf->next_z);
	}
	else if (v_case == 2)
	{
		if (labs(fdf->cur_y - n) <= labs(fdf->next_y - n))
			return (fdf->cur_z);
		else
			return (fdf->next_z);
	}
	return (0);
}
