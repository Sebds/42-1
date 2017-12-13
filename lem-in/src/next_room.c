/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:44:36 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_next_room(int current_room, t_ant *ant)
{
	int i;

	i = -1;
	while (++i < ant->rooms_number - 1)
		if (ant->shortest_path[i] == current_room)
			return (ant->shortest_path[i + 1]);
	return (-1);
}

int		ft_next_room_is_free(int current_room, t_ant *ant)
{
	int i;

	i = -1;
	while (++i < ant->rooms_number - 1)
	{
		if (ant->shortest_path[i] == current_room)
		{
			if (ant->occupation[i + 1] == 0)
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

char	*ft_next_room_name(int current_room, t_ant *ant)
{
	int index;

	index = ft_next_room(current_room, ant);
	if (index >= 0)
		return (ant->matrix[index].name);
	return (NULL);
}

void	ft_register_ant(t_pos *pos, t_ant *ant)
{
	int i;

	pos->current_room = ft_next_room(pos->current_room, ant);
	i = -1;
	while (++i < ant->rooms_number)
	{
		if (pos->current_room == ant->shortest_path[i])
		{
			if (i != ant->shortest_len)
				ant->occupation[i] = 1;
			ant->occupation[i - 1] = 0;
			break ;
		}
	}
}
