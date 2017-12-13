/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evil_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/06 21:14:00 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_place_next_to_challenger(t_env *info)
{
	int i;
	int j;

	i = -info->p_line;
	while (++i < info->b_line + info->p_line)
	{
		j = -info->p_col;
		while (++j < info->b_col + info->p_col)
		{
			if (ft_can_place(info, i, j, 0))
			{
				if (ft_get_distance(info, i, j) == info->distance)
				{
					ft_printf("%d %d\n", i, j);
					return ;
				}
			}
		}
	}
}

int		ft_choose(t_env *info, int x, int y)
{
	if (ft_is_challenger(info->board[y][x], info) && info->count >= 2)
		return (1);
	if (ft_is_champion(info->board[y][x], info) && info->count < 2)
		return (1);
	return (0);
}

int		ft_get_distance(t_env *info, int i, int j)
{
	int radius;
	int x;
	int y;

	radius = 0;
	while (++radius)
	{
		y = i - radius;
		while (y <= i + radius)
		{
			x = j - radius;
			while (x <= j + radius)
			{
				if (x >= 0 && x < info->b_col && y >= 0 && y < info->b_line)
					if (ft_choose(info, x, y))
						return (radius);
				x++;
			}
			y++;
		}
	}
	return (-1);
}

void	ft_evil_strategy_distance(t_env *info)
{
	int i;
	int j;
	int	tested_distance;

	info->distance = info->b_line * info->b_col;
	i = -info->p_line;
	while (++i < info->b_line + info->p_line)
	{
		j = -info->p_col;
		while (++j < info->b_col + info->p_col)
		{
			if (ft_can_place(info, i, j, 0))
			{
				tested_distance = ft_get_distance(info, i, j);
				if (tested_distance < info->distance)
					info->distance = tested_distance;
			}
		}
	}
	if (info->distance == info->b_line * info->b_col)
		ft_quit("Could not place piece or radius too big\n", info);
	else
		ft_place_next_to_challenger(info);
}
