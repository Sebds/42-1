/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:09:30 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/21 13:06:00 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
**	Checks if there is empty ('.') space on index pos(ition) on map, by shape
*/

int		ft_can_put_tetro(char **map, int size, t_tetro *tetro, int pos)
{
	int		x;
	int		y;
	int		line;
	int		column;
	int		count;

	count = 0;
	line = 0;
	x = pos / size - 1;
	while (++x < size && line < 4)
	{
		y = pos % size - 1;
		column = 0;
		while (++y < size && column < 4)
		{
			if (map[x][y] == '.' && tetro->shape[line][column] == 1)
				count++;
			if (map[x][y] != '.' && tetro->shape[line][column] == 1)
				return (0);
			column++;
		}
		line++;
	}
	return ((count == 4) ? 1 : 0);
}

/*
**	Kindof iteratif backtracking... Failed the fully recursive one... :(
*/

char	**ft_backtracking(char **map, int size, t_tetro *tetro, char letter)
{
	int	pos;

	pos = 0;
	if (ft_valid_map(map, size, letter))
	{
		ft_print_map(map, size);
		exit(0);
	}
	while (pos < size * size - 1)
	{
		if (ft_can_put_tetro(map, size, tetro, pos))
		{
			ft_put_tetro(map, size, tetro, pos);
			if (ft_backtracking(map, size, tetro->next, letter))
				return (map);
			if (!tetro->next)
				return (map);
			ft_clean_map(map, size, tetro->letter);
		}
		pos++;
	}
	return (NULL);
}
