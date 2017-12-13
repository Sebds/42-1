/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_ends.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 09:19:59 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_check_dead_ends(t_ant *ant)
{
	int i;
	int j;
	int k;
	int count;

	i = -1;
	while (++i < ant->rooms_number)
	{
		if (i == ant->start_index || i == ant->end_index)
			continue ;
		count = 0;
		j = -1;
		while (++j < ant->rooms_number)
			(ant->pipes[i][j] == 1) ? count++ : 0;
		if (count == 1)
		{
			k = -1;
			while (++k < ant->rooms_number)
			{
				ant->pipes[i][k] = 0;
				ant->pipes[k][i] = 0;
			}
			i = -1;
		}
	}
}

void	ft_check_double_rooms(t_ant *ant)
{
	int i;
	int j;

	i = -1;
	while (++i < ant->rooms_number)
	{
		j = i;
		while (++j < ant->rooms_number)
			if (ft_strequ(ant->matrix[i].name, ant->matrix[j].name))
				ft_quit("Redefinition of room");
	}
}
