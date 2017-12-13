/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:03:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/31 23:03:46 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libftprintf/includes/libftprintf.h"
# include "../libmlx/mlx.h"

# include <fcntl.h>
# include <limits.h>
# include <math.h>

# define MAX_WIN_HEIGHT 1080
# define NO_COLOR		0
# define WHITE_FLAT		1

typedef struct		s_fdf
{
	int				fd;

	int				file_lines;
	int				file_columns;

	int				**coord;
	int				cols_max;

	void			*mlx;
	void			*win;
	void			*frame_address;
	int				*frame;
	int				**split_frame;

	int				height;
	int				width;
	int				height_scale;
	int				width_scale;

	int				i;
	int				j;
	int				index_i;
	int				index_j;

	int				cur_x;
	int				cur_y;
	float			cur_z;
	int				next_x;
	int				next_y;
	float			next_z;

	float			cpy_cz;
	float			cpy_nz;

	int				v;
	int				h;
	float			coef;
	float			alt;
	float			alt_max;

	int				no_color;
	int				white_flat;
}					t_fdf;

void				ft_write_color(t_fdf *fdf, int x, int y, float color);
void				ft_write_buffer_color(t_fdf *fdf, int x, int y, float z);
int					ft_get_color_between_coord(t_fdf *fdf, int x, int v_case);

float				ft_calc_x_iso(t_fdf *fdf, int x, int y);
float				ft_calc_y_iso(t_fdf *fdf, int x, int y, float z);
void				ft_thales_x(t_fdf *fdf, float z);
void				ft_thales_y(t_fdf *fdf, float z);

void				ft_check_swap(t_fdf *fdf);
void				ft_put_mem_line(t_fdf *fdf);
void				ft_draw_line_h(t_fdf *fdf, int y, int x);
void				ft_draw_line_v(t_fdf *fdf, int y, int x);
void				ft_draw(t_fdf *fdf);

void				ft_scale(t_fdf *fdf);
int					ft_get_key(int key, t_fdf *fdf);
void				ft_init_split_frame(t_fdf *fdf);
void				ft_init_mlx(t_fdf *fdf);

int					ft_tab_len(char **tab);
void				ft_get_file_dim(t_fdf *fdf);
void				ft_get_alt_max(t_fdf *fdf);
void				ft_parse_map(t_fdf *fdf, int i, int j);

void				ft_swap_x(t_fdf *fdf);
void				ft_swap_y(t_fdf *fdf);

#endif
