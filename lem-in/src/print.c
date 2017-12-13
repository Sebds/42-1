/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:18:30 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_print_occupation(t_ant *ant)
{
	int i;

	i = -1;
	ft_printf("\n");
	while (++i < ant->rooms_number)
		ft_printf("%d ", ant->occupation[i]);
	ft_printf("\n");
}

void	ft_move_ants(t_ant *ant, t_pos *pos)
{
	char *room;

	while (pos)
	{
		if (ft_next_room_is_free(pos->current_room, ant))
		{
			if (pos->current_room != ant->end_index)
			{
				room = ft_next_room_name(pos->current_room, ant);
				ft_printf("L%d-%s ", pos->num, room);
				ft_register_ant(pos, ant);
			}
		}
		pos = pos->next;
	}
}

int		ft_all_at_end(t_pos *pos, int end_index)
{
	while (pos)
	{
		if (pos->current_room != end_index)
			return (0);
		pos = pos->next;
	}
	return (1);
}

void	ft_one_step(t_ant *ant)
{
	int i;

	i = -1;
	while (++i < ant->ant_number)
		ft_printf("L%d-%s ", i + 1, ant->matrix[ant->end_index].name);
	ft_printf("\n");
}

void	ft_init_print(t_ant *ant)
{
	t_pos *pos;

	if (ft_count_shortest_steps(ant) == 1)
	{
		ft_one_step(ant);
		return ;
	}
	pos = ft_create_pos(ant);
	ant->pos = pos;
	while (!ft_all_at_end(pos, ant->end_index))
	{
		ft_move_ants(ant, pos);
		ft_printf("\n");
	}
}
