/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_kernel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:04:22 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/06 16:04:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	build_kernel(t_kernel *kernel, int id)
{
	cl_int ret;

	kernel->program = clCreateProgramWithSource(kernel->context, 1, \
						(const char **)&kernel->source_str, \
						(const size_t *)&kernel->source_size, &ret);
	ret = clBuildProgram(kernel->program, 0, NULL, NULL, NULL, NULL);
	if (id == 1)
		kernel->kernel = clCreateKernel(kernel->program, "julia", &ret);
	if (id == 2)
		kernel->kernel = clCreateKernel(kernel->program, "mandel", &ret);
	if (id == 3)
		kernel->kernel = clCreateKernel(kernel->program, "ship", &ret);
	if (id == 4)
		kernel->kernel = clCreateKernel(kernel->program, "quartz", &ret);
	if (id == 5)
		kernel->kernel = clCreateKernel(kernel->program, "julia3", &ret);
	ret = clSetKernelArg(kernel->kernel, 0, sizeof(cl_mem), &kernel->input);
	ret = clSetKernelArg(kernel->kernel, 1, sizeof(cl_mem), &kernel->results);
	ft_printf("Kernel %d built.\n", id);
}
