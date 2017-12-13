/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:30:51 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/26 22:30:51 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_mem_line(t_fdf *fdf)
{
	fdf->cur_z = fdf->cpy_cz;
	fdf->next_z = fdf->cpy_nz;
	if (abs(fdf->next_x - fdf->cur_x) > abs(fdf->next_y - fdf->cur_y))
		ft_thales_x(fdf, 0);
	else
		ft_thales_y(fdf, 0);
}

void	ft_draw_line_h(t_fdf *fdf, int y, int x)
{
	int i;
	int j;

	i = fdf->i;
	j = fdf->j;
	fdf->cur_x = x;
	fdf->cur_y = y;
	fdf->cpy_cz = fdf->coord[fdf->index_i][fdf->index_j] * fdf->alt;
	fdf->cpy_cz = fdf->coord[fdf->index_i][fdf->index_j];
	j += fdf->width_scale;
	if (j >= fdf->width)
		return ;
	fdf->next_z = fdf->coord[i / fdf->height_scale][(j / fdf->width_scale) + 1];
	fdf->next_z *= fdf->alt;
	fdf->cpy_nz = fdf->coord[i / fdf->height_scale][(j / fdf->width_scale) + 1];
	fdf->next_x = ft_calc_x_iso(fdf, j, i) + fdf->h;
	fdf->next_y = ft_calc_y_iso(fdf, j, i, fdf->next_z) + fdf->v;
	ft_put_mem_line(fdf);
}

void	ft_draw_line_v(t_fdf *fdf, int y, int x)
{
	int i;
	int j;

	i = fdf->i;
	j = fdf->j;
	fdf->cur_x = x;
	fdf->cur_y = y;
	fdf->cur_z = fdf->coord[fdf->index_i][fdf->index_j] * fdf->alt;
	fdf->cpy_cz = fdf->coord[fdf->index_i][fdf->index_j];
	i += fdf->height_scale;
	if (i / fdf->height_scale >= fdf->file_lines)
		return ;
	fdf->next_z = fdf->coord[i / fdf->height_scale][(j / fdf->width_scale) + 1];
	fdf->next_z *= fdf->alt;
	fdf->cpy_nz = fdf->coord[i / fdf->height_scale][(j / fdf->width_scale) + 1];
	fdf->next_x = ft_calc_x_iso(fdf, j, i) + fdf->h;
	fdf->next_y = ft_calc_y_iso(fdf, j, i, fdf->next_z) + fdf->v;
	ft_put_mem_line(fdf);
}

void	ft_draw(t_fdf *fdf)
{
	int		i;
	int		j;
	int		x;
	int		y;
	float	z;

	i = fdf->height_scale / 2;
	while (i / fdf->height_scale <= fdf->file_lines - 1)
	{
		j = fdf->width_scale / 2;
		while (j < fdf->width)
		{
			fdf->index_i = i / fdf->height_scale;
			fdf->index_j = (j / fdf->width_scale) + 1;
			fdf->i = i;
			fdf->j = j;
			z = fdf->coord[fdf->index_i][fdf->index_j] * fdf->alt;
			x = ft_calc_x_iso(fdf, j, i) + fdf->h;
			y = ft_calc_y_iso(fdf, j, i, z) + fdf->v;
			ft_draw_line_h(fdf, y, x);
			ft_draw_line_v(fdf, y, x);
			j += fdf->width_scale;
		}
		i += fdf->height_scale;
	}
}
