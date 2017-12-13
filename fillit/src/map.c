/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelmalem <jelmalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:18:07 by jelmalem          #+#    #+#             */
/*   Updated: 2016/11/14 18:18:07 by jelmalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** This function creates a matrix/map of (size * size) full of '.'
*/

char	**ft_map(int size)
{
	char	**map;
	int		count_col;
	int		count_line;

	if ((map = (char **)malloc(sizeof(char *) * size)) == NULL)
		ft_quit("Couldn't malloc map columns");
	count_line = 0;
	while (count_line < size)
	{
		count_col = 0;
		if (!(map[count_line] = (char *)malloc(sizeof(char) * size)))
			ft_quit("Couln't malloc map line");
		while (count_col < size)
		{
			map[count_line][count_col] = '.';
			count_col++;
		}
		map[count_line][count_col] = '\n';
		count_line++;
	}
	return (map);
}

/*
** Display the map of (size * size) on standart output
*/

void	ft_print_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		free(map[i]);
		i++;
	}
	free(map);
}

/*
** Only replace letter (i.e. 'B') by '.' on the map of (size * size)
*/

void	ft_clean_map(char **map, int size, char letter)
{
	int		count_line;
	int		count_col;

	count_line = 0;
	while (count_line < size)
	{
		count_col = 0;
		while (count_col < size)
		{
			if (map[count_line][count_col] == letter)
				map[count_line][count_col] = '.';
			count_col++;
		}
		count_line++;
	}
}

/*
** Checks the presence of ALL blocks of ALL tetrominos, from 'A' to letter
*/

int		ft_valid_map(char **map, int size, char letter)
{
	int		i;
	int		j;
	int		count_letter;
	char	x;

	x = 'A';
	while (x <= letter)
	{
		count_letter = 0;
		i = -1;
		while (++i < size)
		{
			j = -1;
			while (++j < size)
			{
				if (map[i][j] == x)
					count_letter++;
			}
		}
		if (count_letter != 4)
			return (0);
		x++;
	}
	return (1);
}

/*
** Put ONE tetro on the (size * size) map, to a given position (in index)
*/

void	ft_put_tetro(char **map, int size, t_tetro *tetro, int pos)
{
	int		line;
	int		column;
	int		x;
	int		y;

	x = pos / size;
	line = 0;
	while (x < size && line < 4)
	{
		y = pos % size;
		column = 0;
		while (y < size && column < 4)
		{
			if (tetro->shape[line][column] == 1)
				map[x][y] = tetro->letter;
			y++;
			column++;
		}
		x++;
		line++;
	}
}
