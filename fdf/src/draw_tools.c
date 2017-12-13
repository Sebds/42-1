/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:31:16 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/26 22:31:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_calc_x_iso(t_fdf *fdf, int x, int y)
{
	float	coef;
	float	new_x;

	coef = fdf->coef;
	new_x = (coef) * (x - y);
	return (new_x + (fdf->width / 2));
}

float	ft_calc_y_iso(t_fdf *fdf, int x, int y, float z)
{
	float	coef_1;
	float	coef_2;
	float	new_y;

	coef_1 = fdf->coef;
	coef_2 = fdf->coef;
	new_y = ((coef_1 * z) - (coef_2 * (x + y)));
	return (new_y + fdf->height);
}

void	ft_thales_x(t_fdf *fdf, float z)
{
	int	x;
	int	y;

	ft_swap_x(fdf);
	x = fdf->cur_x;
	while (x <= fdf->next_x && fdf->next_x != fdf->cur_x)
	{
		y = (fdf->next_y - fdf->cur_y) * (x - fdf->cur_x);
		y /= (fdf->next_x - fdf->cur_x);
		y += fdf->cur_y;
		z = ft_get_color_between_coord(fdf, x, 1);
		if (x > 0 && y > 0 && x < fdf->width && y < fdf->height)
			ft_write_buffer_color(fdf, x, y, z);
		x++;
	}
}

void	ft_thales_y(t_fdf *fdf, float z)
{
	int	x;
	int	y;

	ft_swap_y(fdf);
	y = fdf->cur_y;
	while (y <= fdf->next_y && fdf->next_y != fdf->cur_y)
	{
		x = (fdf->next_x - fdf->cur_x) * (y - fdf->cur_y);
		x /= (fdf->next_y - fdf->cur_y);
		x += fdf->cur_x;
		z = ft_get_color_between_coord(fdf, y, 2);
		if (x > 0 && y > 0 && x < fdf->width && y < fdf->height)
			ft_write_buffer_color(fdf, x, y, z);
		y++;
	}
}
