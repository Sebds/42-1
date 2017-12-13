/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:40:26 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_print_solution(t_ant *ant)
{
	if (ant->min_steps >= ant->rooms_number)
		ft_quit("Not solvable :(");
	else
	{
		ft_printf("%s%s%s\n", ant->ants_line, ant->rooms_line, ant->pipes_line);
		if (LEM_IN_DEBUG)
			ft_print_steps(ant);
	}
}

void	ft_solve(t_ant *ant, int start)
{
	int i;
	int count;

	count = ft_count_steps(ant);
	if (start == ant->end_index || count >= ant->min_steps)
	{
		count = ft_count_steps(ant);
		if (count < ant->min_steps)
		{
			ant->min_steps = count;
			ft_dup_step_hist(ant);
		}
		return ;
	}
	i = -1;
	while (++i < ant->rooms_number && ant->ite <= MAX_ITE)
	{
		if (ant->pipes[start][i] == 1 && ft_is_not_in_hist(i, ant))
		{
			ft_push_hist(ant->hist, ant->rooms_number, i);
			ft_solve(ant, i);
			ft_pop_hist(ant->hist, ant->rooms_number);
		}
		ant->ite++;
	}
}
