/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 13:12:49 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:24:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	try_rotate(t_stack *a)
{
	rotate(a);
	swap(a);
	if (is_sort(a) && a->len > 2)
		ft_printf("ra\nsa\n");
	else
	{
		swap(a);
		reverse_rotate(a);
	}
	reverse_rotate(a);
	swap(a);
	if (is_sort(a) && a->len > 2)
		ft_printf("rra\nsa\n");
	else
	{
		swap(a);
		rotate(a);
	}
}

void	try_swap(t_stack *a, t_stack *b)
{
	try_rotate(a);
	swap(a);
	swap(b);
	if (is_sort(a) && is_reverse_sort(b) && a->len > 2)
		ft_printf("ss\n");
	else if (is_sort(a) && !is_reverse_sort(b) && a->len > 2)
	{
		ft_printf("sa\n");
		swap(b);
	}
	else if (!is_sort(a) && is_reverse_sort(b) && a->len > 2)
	{
		ft_printf("sb\n");
		swap(a);
	}
	else
	{
		swap(a);
		swap(b);
	}
	try_rotate(a);
}

void	rotate_min_to_top(t_stack *a, int min)
{
	if (stack_index(a, min) >= a->len / 2)
	{
		while (a->stack[a->len - 1] != min)
		{
			rotate(a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (a->stack[a->len - 1] != min)
		{
			reverse_rotate(a);
			ft_printf("rra\n");
		}
	}
}

void	quint(t_stack *a, t_stack *b)
{
	int min;

	while (!is_sort(a))
	{
		try_swap(a, b);
		min = get_min(a);
		rotate_min_to_top(a, min);
		place_in_helper(a, b);
	}
	place_to_initial_stack(a, b);
}
