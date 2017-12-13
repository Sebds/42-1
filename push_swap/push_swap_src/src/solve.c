/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:03:00 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:22:26 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_push_a(t_stack *b, int median)
{
	int var_next_push;

	var_next_push = next_push(b, median);
	if (var_next_push > b->len / 2)
	{
		rotate(b);
		ft_printf("rb\n");
	}
	else
	{
		reverse_rotate(b);
		ft_printf("rrb\n");
	}
}

void	rotate_to_push_b(t_stack *a, int median)
{
	int var_next_push;

	var_next_push = next_push(a, median);
	if (var_next_push > a->len / 2)
	{
		rotate(a);
		ft_printf("ra\n");
	}
	else
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
}

void	quicksort1(t_stack *a, t_stack *b)
{
	int median;
	int len;

	len = a->len;
	while (a->len > len / 2)
	{
		median = get_median(a);
		while (median != get_min(a) && a->len > len / 2)
		{
			if (a->stack[a->len - 1] < median)
			{
				push(a, b);
				ft_printf("pb\n");
			}
			else
				rotate_to_push_b(a, median);
		}
	}
}

void	quicksort2(t_stack *a, t_stack *b)
{
	int median;

	while (b->len > 1)
	{
		median = get_median(b);
		while (median != get_min(b) || median != b->stack[b->len - 1])
		{
			if (b->stack[b->len - 1] < median)
			{
				push(b, a);
				ft_printf("pa\n");
			}
			else
			{
				rotate_to_push_a(b, median);
			}
		}
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->len == 2)
	{
		duo(a);
		return ;
	}
	if (a->len == 3)
	{
		trio(a);
		return ;
	}
	if (a->len <= 32)
	{
		quint(a, b);
		return ;
	}
	quicksort1(a, b);
	quicksort2(a, b);
	quicksort1(a, b);
	quicksort(a, b);
	insertion(a, b);
}
