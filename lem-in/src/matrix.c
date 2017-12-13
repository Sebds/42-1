/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 22:31:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	MATRIX ROOM
*/

char	*ft_get_room_name(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, ' ');
	return (ft_strsub(str, 0, ptr - str));
}

void	ft_matrix_rooms(t_ant *ant)
{
	int		i;
	int		count;
	char	*line;

	i = -1;
	count = 0;
	while (ant->split_rooms[++i])
	{
		if (ft_room_pattern(ant->split_rooms[i]))
		{
			line = ft_get_room_name(ant->split_rooms[i]);
			ant->matrix[count].name = line;
			if (i > 0 && ft_comment_pattern(ant->split_rooms[i - 1]) == 2)
				ant->start_index = count;
			if (i > 0 && ft_comment_pattern(ant->split_rooms[i - 1]) == 3)
				ant->end_index = count;
			count++;
		}
	}
	if (ant->start_index == -1 || ant->end_index == -1)
		ft_quit("Failed to find start/end index");
}

int		ft_search_matrix_index(t_ant *ant, char *str)
{
	int		i;

	i = -1;
	while (++i < ant->rooms_number)
		if (ft_strequ(ant->matrix[i].name, str))
			return (i);
	return (-1);
}

/*
**	MATRIX PIPES
*/

void	ft_fill_pipes(t_ant *ant)
{
	int		i;
	int		x;
	int		y;
	char	**split;

	i = -1;
	while (ant->split_pipes[++i])
	{
		if (ft_pipe_pattern(ant->split_pipes[i]))
		{
			split = ft_strsplit(ant->split_pipes[i], '-');
			if (split == NULL)
				ft_quit("Could not split line");
			x = ft_search_matrix_index(ant, split[0]);
			y = ft_search_matrix_index(ant, split[1]);
			ft_free_tab(split);
			if (x < 0 || y < 0)
				continue ;
			ant->pipes[x][y] = 1;
			ant->pipes[y][x] = 1;
		}
	}
}

void	ft_matrix_pipes(t_ant *ant)
{
	int		i;
	int		j;

	i = -1;
	while (++i < ant->rooms_number)
	{
		ant->pipes[i] = (int *)malloc(sizeof(int) * ant->rooms_number);
		if (ant->pipes[i] == NULL)
			ft_quit("Could not alloc pipe line in pipe matrix");
	}
	i = -1;
	while (++i < ant->rooms_number)
	{
		j = -1;
		while (++j < ant->rooms_number)
			ant->pipes[i][j] = 0;
	}
	ft_fill_pipes(ant);
}
