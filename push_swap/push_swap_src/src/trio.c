/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trio.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 13:12:49 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:09:13 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trio(t_stack *a)
{
	int min;

	while (!is_sort(a))
	{
		min = get_min(a);
		if (stack_index(a, min) >= a->len / 2)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else
		{
			reverse_rotate(a);
			ft_printf("rra\n");
		}
		if (!is_sort(a))
		{
			swap(a);
			ft_printf("sa\n");
		}
	}
}
