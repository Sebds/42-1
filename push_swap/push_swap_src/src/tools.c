/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:23:04 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:12:34 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_in_helper(t_stack *a, t_stack *b)
{
	if (!is_sort(a) || (get_min(a) < get_max(b)))
	{
		push(a, b);
		ft_printf("pb\n");
	}
}

void	place_to_initial_stack(t_stack *a, t_stack *b)
{
	while (b->len)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}

int		is_sort(t_stack *a)
{
	int i;

	i = a->len;
	while (i-- > 1)
		if (a->stack[i] > a->stack[i - 1])
			return (0);
	return (1);
}

int		is_reverse_sort(t_stack *a)
{
	int i;

	i = a->len;
	if (a->len <= 1)
		return (0);
	while (i-- > 1)
		if (a->stack[i] < a->stack[i - 1])
			return (0);
	return (1);
}
