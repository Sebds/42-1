/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 22:31:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 23:24:11 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*realloc_line(char *in, char *add)
{
	char *new_line;

	if (!in || !add)
		return (NULL);
	new_line = ft_strnew(ft_strlen(in) + ft_strlen(add) + 1);
	if (!new_line)
		return (NULL);
	ft_strcpy(new_line, in);
	ft_strcat(new_line, add);
	ft_strcat(new_line, "\n");
	free(in);
	in = NULL;
	free(add);
	add = NULL;
	return (new_line);
}

void	get_ants(t_ant *ant, char *line)
{
	if (ft_comment_pattern(line) == 1)
		ft_quit("Illegal 'L' Line");
	if (ft_is_number(line))
	{
		ant->ants_line = realloc_line(ant->ants_line, line);
		ant->bloc = 2;
	}
	else if (ft_comment_pattern(line) > 1)
	{
		ant->ants_line = realloc_line(ant->ants_line, line);
	}
	else
		ft_quit("No ants detected");
}

void	get_rooms(t_ant *ant, char *line)
{
	if (ft_comment_pattern(line) == 1)
		ft_quit("Illegal 'L' Line");
	if (ft_room_pattern(line))
	{
		ant->rooms_line = realloc_line(ant->rooms_line, line);
	}
	else if (ft_comment_pattern(line) > 1)
	{
		ant->rooms_line = realloc_line(ant->rooms_line, line);
	}
	else if (ft_pipe_pattern(line))
	{
		ant->pipes_line = realloc_line(ant->pipes_line, line);
		ant->bloc = 3;
		ant->got_pipes = 1;
	}
	else
		ft_quit("Unvalid map description");
}

void	get_pipes(t_ant *ant, char *line)
{
	if (ft_comment_pattern(line) == 1)
		ft_quit("L Line");
	if (ft_pipe_pattern(line))
	{
		ant->pipes_line = realloc_line(ant->pipes_line, line);
		ant->got_pipes = 1;
	}
	else if (ft_comment_pattern(line) > 1)
	{
		ant->pipes_line = realloc_line(ant->pipes_line, line);
		ant->got_pipes = 1;
	}
	else if (!ant->got_pipes)
		ft_quit("Unvalid map description");
	else
		ant->bloc = 4;
}

void	ft_read_input(t_ant *ant)
{
	char	*line;

	line = NULL;
	ant->bloc = 1;
	ant->got_pipes = 0;
	ant->ants_line = ft_strdup("\0");
	ant->rooms_line = ft_strdup("\0");
	ant->pipes_line = ft_strdup("\0");
	while (get_next_line(0, &line) == 1)
	{
		if (ant->bloc == 1)
			get_ants(ant, line);
		else if (ant->bloc == 2)
			get_rooms(ant, line);
		else if (ant->bloc == 3)
			get_pipes(ant, line);
		if (ant->bloc == 4)
			break ;
	}
	(ant->bloc != 4 && ant->got_pipes == 0) ? ft_quit("No input") : 0;
	free(line);
	ant->split_ants = ft_strsplit(ant->ants_line, '\n');
	ant->split_rooms = ft_strsplit(ant->rooms_line, '\n');
	ant->split_pipes = ft_strsplit(ant->pipes_line, '\n');
}
