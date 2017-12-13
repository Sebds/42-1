/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:43:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/09 20:45:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol_usage(void)
{
	ft_printf("Usage : \n");
	ft_printf("./fractol [julia|mandelbrot|burnship|quartz|julia3]\n\n");
	ft_printf("Manual :\n");
	ft_printf("W | Left clic | Scroll up : zoom in\n");
	ft_printf("Q : Right clic | Scroll down : zoom out\n");
	ft_printf("Arrow keys : translate\n");
	ft_printf("= : increase max incrementation\n");
	ft_printf("- : decrease max incrementation\n");
	ft_printf("R : reset\n");
	ft_printf("1 | 2 | 3 | 4 | 5 : choose fractal\n");
	ft_printf("C : change color\n");
	ft_printf("B : black and white\n");
	ft_printf("I : info box\n\n");
	exit(0);
}

void	get_fractal_type(t_env *env, int argc, char **argv)
{
	if (argc != 2)
		fractol_usage();
	else if (ft_strequ(argv[1], "julia"))
		env->cur = 1;
	else if (ft_strequ(argv[1], "mandelbrot"))
		env->cur = 2;
	else if (ft_strequ(argv[1], "burnship"))
		env->cur = 3;
	else if (ft_strequ(argv[1], "quartz"))
		env->cur = 4;
	else if (ft_strequ(argv[1], "julia3"))
		env->cur = 5;
	else
		fractol_usage();
}

int		main(int argc, char **argv)
{
	t_env	env;

	init_env(&env);
	get_fractal_type(&env, argc, argv);
	init_mlx(&env);
	init_kernel(&env.julia.kernel, 1);
	init_kernel(&env.mandel.kernel, 2);
	init_kernel(&env.ship.kernel, 3);
	init_kernel(&env.quartz.kernel, 4);
	init_kernel(&env.julia3.kernel, 5);
	compute(&env);
	mlx_loop(env.mlx);
	return (0);
}
