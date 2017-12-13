/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:35:22 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/06 16:35:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libmlx/mlx.h"
# include "../libftprintf/includes/libftprintf.h"
# include <openCL/openCL.h>
# include <time.h>
# include <sys/time.h>
# include <stdio.h>

# define F_WIDTH			1920
# define F_HEIGHT			1080

# define MAX_SOURCE_SIZE	0x100000

# define ITE_MAX_DEFAULT	1500
# define ITE_INCREMENTATION 60
# define ZOOM_INCREMENTATON 1.5

# define LEFT_CLIC			1
# define RIGHT_CLIC			2
# define SCROLL_UP			5
# define SCROLL_DOWN		4

# define COMMAND_QUEUE	kernel->command_queue
# define INPUT			kernel->input
# define KERNEL			kernel->kernel
# define DEVICEID		kernel->device_id
# define LOCAL			kernel->local

typedef struct			s_kernel
{
	cl_program			program;
	cl_device_id		device_id;
	cl_context			context;
	cl_kernel			kernel;
	cl_command_queue	command_queue;
	char				*source_str;
	size_t				source_size;
	cl_mem				input;
	cl_mem				results;
	size_t				local;
}						t_kernel;

typedef struct			s_julia
{
	double				c_x;
	double				c_y;
	struct s_kernel		kernel;
}						t_julia;

typedef struct			s_mandel
{
	struct s_kernel		kernel;
}						t_mandel;

typedef struct			s_ship
{
	struct s_kernel		kernel;
}						t_ship;

typedef struct			s_quartz
{
	double				c_x;
	double				c_y;
	struct s_kernel		kernel;
}						t_quartz;

typedef struct			s_julia3
{
	double				c_x;
	double				c_y;
	struct s_kernel		kernel;
}						t_julia3;

typedef struct			s_env
{
	double				max_ite;
	double				zoom;
	double				h;
	double				v;
	int					eq;
	int					random;

	void				*mlx;
	void				*win;
	int					*frame;
	void				*frame_addr;

	void				*box_info;
	int					display_box;

	struct s_julia		julia;
	struct s_mandel		mandel;
	struct s_ship		ship;
	struct s_quartz		quartz;
	struct s_julia3		julia3;

	int					cur;
}						t_env;

void					init_env(t_env *env);

void					init_mlx(t_env *env);

void					init_kernel(t_kernel *kernel, int id);

void					build_kernel(t_kernel *kernel, int id);

void					fill_data(double *input, t_env *env);
void					run_kernel(t_kernel *kernel, t_env *env);
void					compute(t_env *env);

int						e_key_input(int key, t_env *env);

int						e_mouse_input(int clic, int x, int y, t_env *env);
int						e_mouse_move(int x, int y, t_env *env);

void					box_info(t_env *env);
void					update_box_info(t_env *env);

#endif
