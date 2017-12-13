/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/06 21:18:25 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_reset_visualizer(t_env *info)
{
	info->total_champion = 0;
	info->total_challenger = 0;
}

void	ft_draw_cell(t_env *info, int x, int y, unsigned int color)
{
	int i;
	int j;

	if (info->split_frame[y][x] == (int)color)
		return ;
	i = y;
	while (i < y + info->height_scale)
	{
		j = x;
		while (j < x + info->width_scale)
		{
			if (i > 0 && j > 0 && i < info->height && j < info->width)
				info->split_frame[i][j] = color;
			j++;
		}
		i++;
	}
}

void	ft_update_visualizer(t_env *info, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < info->b_line)
	{
		j = -1;
		while (++j < info->b_col)
		{
			x = j * info->width_scale;
			y = i * info->height_scale;
			(info->board[i][j] == 'O') ? info->total_champion++ : 0;
			(info->board[i][j] == 'O') ? ft_draw_cell(info, x, y, 0xFF0000) : 0;
			(info->board[i][j] == 'X') ? info->total_challenger++ : 0;
			(info->board[i][j] == 'X') ? ft_draw_cell(info, x, y, 0x00FF00) : 0;
			(info->board[i][j] == '.') ? ft_draw_cell(info, x, y, 0x000000) : 0;
			(info->board[i][j] == '=') ? ft_draw_cell(info, x, y, 0x0000FF) : 0;
		}
	}
}

void	ft_display_score(t_env *info)
{
	int		x;
	int		y;
	char	*total;

	x = 10;
	y = info->height + 5;
	mlx_string_put(info->mlx, info->win, x, y, 0xFF0000, "p1 : ");
	x = 10;
	y = info->height + 30;
	mlx_string_put(info->mlx, info->win, x, y, 0x00FF22, "p2 : ");
	x = 100;
	y = info->height + 5;
	total = ft_itoa(info->total_champion);
	mlx_string_put(info->mlx, info->win, x, y, 0xFF0000, total);
	free(total);
	x = 100;
	y = info->height + 30;
	total = ft_itoa(info->total_challenger);
	mlx_string_put(info->mlx, info->win, x, y, 0x00FF22, total);
	free(total);
}
