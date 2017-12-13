/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/06 21:21:11 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_can_place(t_env *e, int x, int y, int count)
{
	int i;
	int j;

	i = -1;
	while (++i < e->p_line && x + e->p_line <= e->b_line + e->p_line)
	{
		j = -1;
		while (++j < e->p_col && y + e->p_col <= e->b_col + e->p_col)
		{
			if (i >= 0 && j >= 0 && i < e->p_line && j < e->p_col)
			{
				if (e->piece[i][j] == '*')
				{
					if (x + i < 0 || y + j < 0 || x + i >= e->b_line ||
						y + j >= e->b_col)
						return (0);
					if (ft_is_champion(e->board[x + i][y + j], e))
						count++;
					else if (ft_is_challenger(e->board[x + i][y + j], e))
						return (0);
				}
			}
		}
	}
	return (count == 1);
}
