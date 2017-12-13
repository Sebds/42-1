/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:01:05 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:16:48 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libftprintf.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <sys/time.h>

# define F_WIDTH	(double)1920
# define F_HEIGHT	(double)1080

# define FPS				30

# define FLOOR_COLOR		0x636363

# define TEXTURE_NUMBER		5
# define TEXTURE_W			255
# define TEXTURE_H			255

# define SKYBOX				"textures/sky_360.xpm"
# define SKYBOX_W			9000
# define SKYBOX_H			2250
# define SKY_SHIFT_COEF		145

# define START				"Welcome to Wolf3D. Go throught the 3 labyrinths !"
# define START2				"Search the wooden doors..."

# define END				"You won the maze !"
# define END_2				"THANKS FOR PLAYING !"
# define END_3				"nsampre - 2017"

# define LVL1				"Level 1."
# define LVL2				"Level 2."
# define LVL3				"Level 3."

typedef struct	s_env
{
	int			i;
	int			map_w;
	int			map_h;
	int			**map;

	double		level_pos_x[3];
	double		level_pos_y[3];
	int			level_map_h[3];
	int			level_map_w[3];
	int			**level_map[3];

	void		*mlx;
	void		*win;

	int			up;
	int			down;
	int			left;
	int			right;
	int			move_left;
	int			move_right;
	int			minimap;

	int			scale_x;
	int			scale_y;

	void		*frame_addr;
	int			*frame;
	int			**frame_array;

	void		*tx_addr[TEXTURE_NUMBER];
	int			*tx[TEXTURE_NUMBER];
	int			**tx_array[TEXTURE_NUMBER];

	void		*sky_addr;
	int			*sky;
	int			**sky_array;
	int			sky_shift;

	double		pos_x;
	double		pos_y;

	double		dir_x;
	double		dir_y;

	double		plane_x;
	double		plane_y;

	double		camera_x;

	double		ray_pos_x;
	double		ray_pos_y;

	double		ray_dir_x;
	double		ray_dir_y;

	int			map_x;
	int			map_y;

	int			side;
	double		side_dist_x;
	double		side_dist_y;

	double		delta_dist_x;
	double		delta_dist_y;

	int			wall_top;
	int			wall_bottom;

	int			step_x;
	int			step_y;

	double		wall_dist;

	int			tx_num;
	int			hit_tx_x;
	int			hit_tx_y;
}				t_env;

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

extern char		*g_tx[TEXTURE_NUMBER];
extern char		*g_level[3];

# endif

void			init_env(t_env *e);
void			load_all_levels(t_env *e);
void			init_mlx(t_env *e);
int				draw(t_env *e);
int				handle_keyboard(t_env *e);
int				wolf_exit(int key);
void			init_ray(t_env *e);
void			launch_ray(t_env *e);
void			compute_column(t_env *e, int column);
void			minimap(t_env *e);
void			choose_level(t_env *e, int i);
void			start_splashscreen(t_env *e);
void			end_splashscreen(t_env *e);
void			level_1_splashscreen(t_env *e);
void			level_2_splashscreen(t_env *e);
void			level_3_splashscreen(t_env *e);
void			up(t_env *e, double move_speed);
void			down(t_env *e, double move_speed);
void			move_left(t_env *e, double move_speed);
void			move_right(t_env *e, double move_speed);
void			left(t_env *e, double rot_speed);
void			right(t_env *e, double rot_speed);

#endif
