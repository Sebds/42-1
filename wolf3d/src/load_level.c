/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:57:53 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/24 20:07:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_map(t_env *e, int fd, int i, int j)
{
	char	**split_line;
	char	*line;
	int		k;

	line = NULL;
	k = -1;
	while (++k < e->level_map_h[e->i] && get_next_line(fd, &line))
	{
		e->level_map[e->i][++i] = (int *)ft_memalloc(sizeof(int) * \
													e->level_map_w[e->i]);
		split_line = ft_strsplit(line, ' ');
		j = -1;
		while (split_line[++j])
		{
			e->level_map[e->i][i][j] = ft_atoi(split_line[j]);
			if (e->level_map[e->i][i][j] == -1)
				e->level_pos_x[e->i] = i + 0.5;
			if (e->level_map[e->i][i][j] == -1)
				e->level_pos_y[e->i] = j + 0.5;
			free(split_line[j]);
		}
		free(split_line);
		free(line);
	}
	close(fd);
}

void	load_level(t_env *e, int i, char *level)
{
	int		fd;
	char	*line;

	if ((fd = open(level, O_RDONLY)) < 0)
		exit(1);
	if (read(fd, 0, 0) < 0)
		exit(1);
	line = NULL;
	get_next_line(fd, &line);
	e->level_map_w[i] = ft_atoi(line);
	free(line);
	get_next_line(fd, &line);
	e->level_map_h[i] = ft_atoi(line);
	free(line);
	e->level_map[i] = (int **)ft_memalloc(sizeof(int *) * \
										(e->level_map_h[i] + 1));
	load_map(e, fd, -1, 0);
}

void	load_all_levels(t_env *e)
{
	int i;

	i = 0;
	while (i < 3)
	{
		e->i = i;
		load_level(e, i, g_level[i]);
		i++;
	}
}
