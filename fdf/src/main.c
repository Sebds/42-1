/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:45:29 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/26 20:45:29 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf fdf;

	if (argc != 2)
		exit(0);
	if ((fdf.fd = open(argv[1], O_RDONLY)) < 0)
		exit(0);
	ft_get_file_dim(&fdf);
	if ((fdf.fd = open(argv[1], O_RDONLY)) < 0)
		exit(0);
	ft_parse_map(&fdf, 0, 0);
	ft_get_alt_max(&fdf);
	ft_init_mlx(&fdf);
	ft_draw(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.frame_address, 0, 0);
	mlx_loop(fdf.mlx);
}
