/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:40:09 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_is_not_in_hist(int index, t_ant *ant)
{
	int i;

	i = -1;
	while (++i < ant->rooms_number)
		if (ant->hist[i] == index)
			return (0);
	return (1);
}

void	ft_push_hist(int *hist, int size, int index)
{
	int i;

	i = -1;
	while (++i < size)
		if (hist[i] == -1)
			break ;
	hist[i] = index;
}

void	ft_pop_hist(int *hist, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (hist[i] == -1)
			break ;
	if (i - 1 >= 0)
		hist[i - 1] = -1;
}

void	ft_dup_step_hist(t_ant *ant)
{
	int i;

	i = -1;
	while (i++ < ant->rooms_number)
		ant->shortest_path[i] = ant->hist[i];
}
