/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 01:00:55 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/30 01:00:55 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_swap_x(t_fdf *fdf)
{
	int	swap;

	if (fdf->cur_x > fdf->next_x)
	{
		swap = fdf->cur_x;
		fdf->cur_x = fdf->next_x;
		fdf->next_x = swap;
		swap = fdf->cur_y;
		fdf->cur_y = fdf->next_y;
		fdf->next_y = swap;
		swap = fdf->cur_z;
		fdf->cur_z = fdf->next_z;
		fdf->next_z = swap;
	}
}

void	ft_swap_y(t_fdf *fdf)
{
	int swap;

	if (fdf->cur_y > fdf->next_y)
	{
		swap = fdf->cur_x;
		fdf->cur_x = fdf->next_x;
		fdf->next_x = swap;
		swap = fdf->cur_y;
		fdf->cur_y = fdf->next_y;
		fdf->next_y = swap;
		swap = fdf->cur_z;
		fdf->cur_z = fdf->next_z;
		fdf->next_z = swap;
	}
}
