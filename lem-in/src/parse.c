/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 22:31:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 23:19:53 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_check_l_and_commands(t_ant *ant)
{
	char *ptr;
	char *tester;

	if (ft_strstr(ant->ants_line, "##start\n") ||
		ft_strstr(ant->ants_line, "##end\n") ||
		ft_strstr(ant->pipes_line, "##start\n") ||
		ft_strstr(ant->pipes_line, "##end\n"))
		ft_quit("Invalid ##start / ##end command");
	ptr = ft_strstr(ant->rooms_line, "##start\n");
	if (!ptr)
		ft_quit("No ##start found");
	tester = ft_strstr(ptr + 7, "##start\n");
	if (tester)
		ft_quit("Duplicate ##start found");
	ptr = ft_strstr(ant->rooms_line, "##end\n");
	if (!ptr)
		ft_quit("No ##end found");
	tester = ft_strstr(ptr + 5, "##end\n");
	if (tester)
		ft_quit("Duplicate ##end found");
}

void	ft_get_ant_number(t_ant *ant)
{
	int	i;
	int	ret;

	i = -1;
	while (ant->split_ants[++i])
	{
		if (ft_is_number(ant->split_ants[i]))
		{
			ret = (int)ft_atoll(ant->split_ants[i]);
			if (ft_strlen(ant->split_ants[i]) <= 6 && ret <= 100000 && ret > 0)
			{
				ant->ant_number = ret;
				return ;
			}
			else
				ft_quit("bad ants number (min 1 | max 100000)");
		}
	}
	ft_quit("Error occured on ft_get_ant_number");
}

void	ft_get_rooms_pipes_number(t_ant *ant)
{
	int i;

	i = -1;
	ant->rooms_number = 0;
	while (ant->split_rooms[++i])
		if (ft_room_pattern(ant->split_rooms[i]))
			ant->rooms_number++;
	i = -1;
	ant->pipes_number = 0;
	while (ant->split_pipes[++i])
		if (ft_pipe_pattern(ant->split_pipes[i]))
			ant->pipes_number++;
}

void	ft_parse(t_ant *ant)
{
	ft_check_l_and_commands(ant);
	ft_get_ant_number(ant);
	ft_get_rooms_pipes_number(ant);
	ant->start_index = -1;
	ant->end_index = -1;
	ant->matrix = (t_room *)malloc(sizeof(t_room) * ant->rooms_number);
	ant->pipes = (int **)malloc(sizeof(int *) * ant->rooms_number);
	if (ant->matrix == NULL || ant->pipes == NULL)
		ft_quit("Failed to alloc matrix|pipe");
	ft_matrix_rooms(ant);
	ft_check_double_rooms(ant);
	ft_matrix_pipes(ant);
	ft_check_dead_ends(ant);
}
