/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/06 21:43:49 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_intlen(unsigned long nbr)
{
	int i;

	i = 1;
	while ((nbr /= 10) > 0)
		i++;
	return (i);
}

void	ft_get_id(t_env *info, char **line)
{
	int		id;

	id = ft_atoi(*line + 10);
	if (id == 1)
		info->letter = 'O';
	else if (id == 2)
		info->letter = 'X';
	else
		ft_quit("Player ID could not be detected\n", info);
	free(*line);
	*line = NULL;
	info->got_char = 1;
}

void	ft_get_board(t_env *info, char **line)
{
	int		i;
	char	**split;

	split = ft_strsplit(*line, ' ');
	ft_check_tab(split);
	info->b_line = ft_atoi(split[1]);
	info->b_col = ft_atoi(split[2]);
	free(*line);
	ft_free_tab(split);
	info->board = NULL;
	info->board = (char **)malloc(sizeof(char *) * (info->b_line));
	if (info->board == NULL)
		ft_quit("Could not alloc split board", info);
	get_next_line(0, line);
	free(*line);
	i = -1;
	while (++i < info->b_line)
	{
		get_next_line(0, line);
		ft_check_line(*line, info->b_col + 4);
		info->board[i] = ft_strdup(*line + 4);
		free(*line);
	}
	*line = NULL;
	info->got_board = 1;
}

void	ft_get_piece(t_env *info, char **line)
{
	int		i;
	char	**split;

	split = ft_strsplit(*line, ' ');
	ft_check_tab(split);
	info->p_line = ft_atoi(split[1]);
	info->p_col = ft_atoi(split[2]);
	free(*line);
	ft_free_tab(split);
	info->piece = NULL;
	info->piece = (char **)malloc(sizeof(char *) * (info->p_line));
	if (info->piece == NULL)
		ft_quit("Could not alloc split piece", info);
	i = -1;
	while (++i < info->p_line)
	{
		get_next_line(0, line);
		ft_check_line(*line, info->p_col);
		info->piece[i] = ft_strdup(*line);
		free(*line);
	}
	*line = NULL;
	info->got_board = 0;
}
