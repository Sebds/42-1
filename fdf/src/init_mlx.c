/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:33:49 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/26 22:33:49 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_scale(t_fdf *fdf)
{
	int ratio;

	fdf->height_scale = 1;
	fdf->height = fdf->file_lines;
	fdf->width = fdf->cols_max * fdf->height_scale;
	fdf->width_scale = fdf->width / fdf->cols_max;
	if (MAX_WIN_HEIGHT > fdf->file_lines / 2)
	{
		ratio = MAX_WIN_HEIGHT / fdf->height + 1;
		fdf->height_scale *= ratio;
		fdf->height *= ratio;
		fdf->width *= ratio;
		fdf->width_scale *= ratio;
	}
}

void	ft_altitude(int key, t_fdf *fdf)
{
	(key == 31) ? fdf->alt += 1 : 0;
	(key == 37) ? fdf->alt -= 1 : 0;
	(key == 34) ? fdf->alt += 0.1 : 0;
	(key == 40) ? fdf->alt -= 0.1 : 0;
	(key == 32) ? fdf->alt += 0.01 : 0;
	(key == 38) ? fdf->alt -= 0.01 : 0;
}

int		ft_get_key(int key, t_fdf *fdf)
{
	(key == 53) ? exit(0) : 0;
	(key == 126 || key == 13) ? fdf->v -= 50 : 0;
	(key == 125 || key == 1) ? fdf->v += 50 : 0;
	(key == 123 || key == 0) ? fdf->h -= 50 : 0;
	(key == 124 || key == 2) ? fdf->h += 50 : 0;
	(key == 78 || key == 12) ? fdf->coef -= 0.05 : 0;
	(key == 69 || key == 14) ? fdf->coef += 0.05 : 0;
	ft_altitude(key, fdf);
	(key == 18) ? (fdf->no_color = 1) : 0;
	(key == 19) ? (fdf->no_color = 0) : 0;
	(key == 20) ? (fdf->no_color = 0) : 0;
	(key == 18) ? (fdf->white_flat = 0) : 0;
	(key == 19) ? (fdf->white_flat = 1) : 0;
	(key == 20) ? (fdf->white_flat = 0) : 0;
	if (key == 15)
	{
		fdf->alt = 0.001;
		fdf->coef = 0.5;
		fdf->v = 0;
		fdf->h = 0;
	}
	ft_bzero(fdf->frame, sizeof(int) * fdf->width * fdf->height);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame_address, 0, 0);
	return (1);
}

void	ft_init_split_frame(t_fdf *fdf)
{
	int i;

	fdf->split_frame = (int **)malloc(sizeof(int *) * fdf->height);
	if (fdf->split_frame == NULL)
		exit(0);
	i = -1;
	while (++i < fdf->height)
		fdf->split_frame[i] = &fdf->frame[i * fdf->width];
	fdf->v = 0;
	fdf->h = 0;
	fdf->coef = 0.5;
	fdf->alt = 0.001;
	fdf->no_color = 1;
}

void	ft_init_mlx(t_fdf *fdf)
{
	int *bits;
	int	*size;
	int	*end;

	bits = (int *)(malloc(sizeof(int) * 1));
	bits[0] = 24;
	size = (int *)(malloc(sizeof(int) * 1));
	size[0] = 8 * fdf->width_scale;
	end = (int *)(malloc(sizeof(int) * 1));
	end[0] = 1;
	if (!(fdf->mlx = mlx_init()))
		exit(0);
	ft_scale(fdf);
	if (!(fdf->win = mlx_new_window(fdf->mlx, fdf->width, fdf->height, "FdF")))
		exit(0);
	fdf->frame_address = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->frame = (int *)mlx_get_data_addr(fdf->frame_address, bits, size, end);
	free(bits);
	free(size);
	free(end);
	ft_init_split_frame(fdf);
	mlx_do_key_autorepeaton(fdf->mlx);
	mlx_hook(fdf->win, 2, (1L << 0), ft_get_key, fdf);
}
