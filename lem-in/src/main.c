/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 22:31:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_ant	*ant;

	ant = (t_ant *)malloc(sizeof(t_ant));
	if (ant == NULL)
		ft_quit("Could not alloc ant structure.");
	ft_read_input(ant);
	ft_parse(ant);
	ft_init_backtrack(ant);
	ft_solve(ant, ant->start_index);
	ft_print_solution(ant);
	ant->shortest_len = ft_count_shortest_steps(ant);
	ft_init_print(ant);
	sleep(LEAKS_TIME);
	return (EXIT_SUCCESS);
}
