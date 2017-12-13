/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:44:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_count_shortest_steps(t_ant *ant)
{
	int i;
	int count;

	i = -1;
	count = -1;
	while (++i < ant->rooms_number)
		if (ant->shortest_path[i] != -1)
			count++;
	return (count);
}

int		ft_count_steps(t_ant *ant)
{
	int i;
	int count;

	i = -1;
	count = -1;
	while (++i < ant->rooms_number)
		if (ant->hist[i] != -1)
			count++;
	return (count);
}

void	ft_print_steps(t_ant *ant)
{
	int i;

	i = -1;
	while (++i < ant->rooms_number)
	{
		if (ant->shortest_path[i] >= 0)
		{
			ft_printf("[%d]", ant->shortest_path[i]);
			ft_printf("%s", ant->matrix[ant->shortest_path[i]].name);
			if (ant->shortest_path[i] != ant->end_index)
				ft_printf(" => ");
		}
		else
			break ;
	}
	ft_printf("\n\n");
}

void	ft_print_instructions(t_ant *ant)
{
	int		i;
	int		j;
	int		path_len;
	char	*room;

	i = 0;
	path_len = ft_count_shortest_steps(ant);
	while (i < ant->ant_number)
	{
		j = 0;
		while (j < path_len)
		{
			room = ant->matrix[ant->shortest_path[j + 1]].name;
			ft_printf("L%d-%s\n", i + 1, room);
			j++;
		}
		i++;
	}
}

void	ft_init_backtrack(t_ant *ant)
{
	int i;

	ant->ite = 0;
	ant->hist = (int *)malloc(sizeof(int) * ant->rooms_number);
	ant->shortest_path = (int *)malloc(sizeof(int) * ant->rooms_number);
	ant->occupation = (int *)malloc(sizeof(int) * ant->rooms_number);
	if (!ant->hist || !ant->shortest_path || !ant->occupation)
		ft_quit("Failed to alloc histoty or shortest path or occup.");
	i = -1;
	while (++i < ant->rooms_number)
	{
		ant->hist[i] = -1;
		ant->shortest_path[i] = -1;
		ant->occupation[i] = 0;
	}
	ant->hist[0] = ant->start_index;
	ant->shortest_path[0] = ant->start_index;
	ant->min_steps = ant->rooms_number;
}
