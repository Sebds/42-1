/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 13:12:49 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:23:17 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_max(t_stack *a)
{
	int i;
	int max;

	i = 0;
	max = a->stack[0];
	while (i < a->len)
	{
		if (a->stack[i] > max)
			max = a->stack[i];
		i++;
	}
	return (max);
}

int		stack_index(t_stack *a, int n)
{
	int i;

	i = -1;
	while (++i < a->len)
		if (n == a->stack[i])
			return (i);
	return (0);
}

void	rotate_max_to_top(t_stack *b, int max)
{
	if (stack_index(b, max) >= b->len / 2)
	{
		while (b->stack[b->len - 1] != max)
		{
			rotate(b);
			ft_printf("rb\n");
		}
	}
	else
	{
		while (b->stack[b->len - 1] != max)
		{
			reverse_rotate(b);
			ft_printf("rrb\n");
		}
	}
}

void	insertion(t_stack *a, t_stack *b)
{
	int max;

	while (b->len)
	{
		max = get_max(b);
		rotate_max_to_top(b, max);
		ft_printf("pa\n");
		push(b, a);
	}
}
