/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:07:15 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/23 10:55:50 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_quit(char *reason)
{
	if (FILLIT_DEBUG)
	{
		ft_putstr(KYEL);
		ft_putstr("[EXIT] Reason : ");
		ft_putendl(reason);
		ft_putstr(KMAG);
		ft_putendl("error");
		ft_putstr(KWHT);
		exit(0);
	}
	else
	{
		ft_putendl("error");
		exit(-1);
	}
}

/*
** get next sqrt
*/

static int	ft_get_next_sqrt(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

/*
** Get the last tetro->letter
*/

static char	ft_find_last_letter(t_tetro *all_tetros)
{
	char letter;

	letter = 0;
	while (all_tetros->next)
	{
		all_tetros = all_tetros->next;
		if (all_tetros->letter)
			letter = all_tetros->letter;
	}
	return (letter);
}

/*
** Backtrack until size is big enough and map is valid
*/

static void	ft_solve(t_tetro *all_tetros, int i)
{
	int		size;
	char	last_letter;
	char	**map;
	char	**empty_map;
	t_tetro	*begin;

	begin = all_tetros;
	if (!begin->next->next)
		last_letter = 'A';
	else
		last_letter = ft_find_last_letter(begin);
	size = ft_get_next_sqrt((last_letter - 64) * 4) - 1;
	map = NULL;
	while (map == NULL && size++)
	{
		empty_map = ft_map(size);
		map = ft_backtracking(empty_map, size, all_tetros, last_letter);
		i = -1;
		while (++i < size)
			free(empty_map[i]);
		free(empty_map);
	}
}

int			main(int argc, char **argv)
{
	int			fd;
	char		full_fd[545 + 1];
	t_split		split_input;
	t_tetro		*all_tetros;

	if (argc != 2)
	{
		ft_putendl("usage : ./fillit <source_file>");
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	ft_strcpy(full_fd, ft_read_input(fd));
	close(fd);
	split_input = ft_split_input(full_fd);
	all_tetros = ft_place_up_and_left(split_input);
	ft_solve(all_tetros, 0);
	exit(1);
	return (1);
}
