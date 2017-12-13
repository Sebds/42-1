/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:23:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/26 22:23:52 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_tab_len(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

void	ft_get_file_dim(t_fdf *fdf)
{
	char	*line;

	fdf->file_lines = 0;
	while (get_next_line(fdf->fd, &line) == 1)
	{
		fdf->file_columns = (int)ft_strlen(line);
		fdf->file_lines++;
		free(line);
	}
	free(line);
	fdf->coord = (int **)malloc(sizeof(int *) * fdf->file_lines + 1);
	close(fdf->fd);
}

void	ft_get_alt_max(t_fdf *fdf)
{
	int i;
	int j;

	fdf->alt_max = INT_MIN;
	i = -1;
	while (++i < fdf->file_lines)
	{
		j = fdf->coord[i][0];
		while (j > 0)
		{
			if (fdf->alt_max < fdf->coord[i][j])
				fdf->alt_max = fdf->coord[i][j];
			if (fdf->alt_max < -fdf->coord[i][j])
				fdf->alt_max = -fdf->coord[i][j];
			j--;
		}
	}
	fdf->alt_max++;
}

void	ft_parse_map(t_fdf *fdf, int i, int j)
{
	char	*line;
	char	**split_line;

	i = fdf->file_lines - 1;
	fdf->cols_max = 0;
	while (get_next_line(fdf->fd, &line) == 1)
	{
		split_line = ft_strsplit(line, ' ');
		fdf->coord[i] = malloc(sizeof(int) * ft_tab_len(split_line) + 1);
		fdf->coord[i][0] = ft_tab_len(split_line);
		if (ft_tab_len(split_line) > fdf->cols_max)
			fdf->cols_max = ft_tab_len(split_line);
		j = 0;
		while (split_line[j])
		{
			fdf->coord[i][j + 1] = -ft_atoi(split_line[j]);
			free(split_line[j]);
			j++;
		}
		free(split_line);
		free(line);
		i--;
	}
	free(line);
	close(fdf->fd);
}
