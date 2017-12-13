/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_kernel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:12:17 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/06 16:12:17 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

FILE	*get_kernel_filename(int id)
{
	FILE	*fp;
	char	*filename;

	filename = NULL;
	if (id == 1)
		filename = ft_strdup("./kernels/julia.cl");
	if (id == 2)
		filename = ft_strdup("./kernels/mandelbrot.cl");
	if (id == 3)
		filename = ft_strdup("./kernels/burnship.cl");
	if (id == 4)
		filename = ft_strdup("./kernels/quartz.cl");
	if (id == 5)
		filename = ft_strdup("./kernels/julia3.cl");
	fp = fopen(filename, "r");
	if (!fp)
	{
		ft_printf("Failed to load kernel %d.\n", id);
		exit(EXIT_FAILURE);
	}
	free(filename);
	return (fp);
}

void	init_kernel(t_kernel *kernel, int id)
{
	cl_platform_id	platform_id;
	cl_uint			ret_num_devices;
	cl_uint			ret_num_platforms;
	cl_int			ret;
	FILE			*fp;

	platform_id = NULL;
	fp = get_kernel_filename(id);
	kernel->source_str = (char *)malloc(MAX_SOURCE_SIZE);
	kernel->source_size = fread(kernel->source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);
	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, \
						&kernel->device_id, &ret_num_devices);
	kernel->context = clCreateContext(NULL, 1, &kernel->device_id, \
									NULL, NULL, &ret);
	kernel->command_queue = clCreateCommandQueue(kernel->context, \
												kernel->device_id, 0, &ret);
	kernel->results = clCreateBuffer(kernel->context, CL_MEM_READ_WRITE, \
									F_HEIGHT * F_WIDTH * sizeof(int), \
									NULL, &ret);
	kernel->input = clCreateBuffer(kernel->context, CL_MEM_READ_WRITE, \
								sizeof(double) * 8, NULL, &ret);
	ft_printf("Kernel %d loaded.\n", id);
	build_kernel(kernel, id);
}
