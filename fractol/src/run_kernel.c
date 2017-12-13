/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_kernel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:04:57 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/06 16:04:57 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fill_data(double *input, t_env *env)
{
	input[0] = env->zoom;
	input[1] = env->h;
	input[2] = env->v;
	input[3] = env->max_ite;
	if (env->cur == 1)
	{
		input[4] = env->julia.c_x;
		input[5] = env->julia.c_y;
	}
	if (env->cur == 4)
	{
		input[4] = env->quartz.c_x;
		input[5] = env->quartz.c_y;
	}
	if (env->cur == 5)
	{
		input[4] = env->julia3.c_x;
		input[5] = env->julia3.c_y;
	}
	input[6] = env->random;
}

void	end_kernel(t_kernel *kernel, int **results)
{
	cl_int ret;

	ret = clFlush(kernel->command_queue);
	ret = clFinish(kernel->command_queue);
	free(*results);
}

void	run_kernel(t_kernel *kernel, t_env *env)
{
	cl_int	ret;
	size_t	global_item_size;
	double	input[7];
	int		*results;

	results = NULL;
	mlx_clear_window(env->mlx, env->win);
	fill_data(input, env);
	if (F_WIDTH * F_HEIGHT > 0)
		results = (int *)malloc(sizeof(int) * F_WIDTH * F_HEIGHT);
	(!results) ? exit(EXIT_FAILURE) : 0;
	ret = clEnqueueWriteBuffer(COMMAND_QUEUE, INPUT, CL_TRUE, 0, \
							sizeof(double) * 8, input, 0, NULL, NULL);
	ret = clGetKernelWorkGroupInfo(KERNEL, DEVICEID, CL_KERNEL_WORK_GROUP_SIZE,\
								sizeof(LOCAL), &LOCAL, NULL);
	global_item_size = F_WIDTH * F_HEIGHT;
	ret = clEnqueueNDRangeKernel(COMMAND_QUEUE, KERNEL, 1, NULL, \
								&global_item_size, &LOCAL, 0, NULL, NULL);
	if (ret)
		ft_printf("FAILURE TO EXEC [%d]\n", ret);
	ret = clEnqueueReadBuffer(COMMAND_QUEUE, kernel->results, CL_TRUE, 0, \
			F_HEIGHT * F_WIDTH * sizeof(int), results, 0, NULL, NULL);
	ft_memcpy(env->frame, results, F_WIDTH * F_HEIGHT * sizeof(int));
	mlx_put_image_to_window(env->mlx, env->win, env->frame_addr, 0, 0);
	end_kernel(kernel, &results);
}

void	compute(t_env *env)
{
	if (env->cur == 1)
		run_kernel(&env->julia.kernel, env);
	if (env->cur == 2)
		run_kernel(&env->mandel.kernel, env);
	if (env->cur == 3)
		run_kernel(&env->ship.kernel, env);
	if (env->cur == 4)
		run_kernel(&env->quartz.kernel, env);
	if (env->cur == 5)
		run_kernel(&env->julia3.kernel, env);
	update_box_info(env);
}
