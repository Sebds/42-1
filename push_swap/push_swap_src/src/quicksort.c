/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:12:24 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:23:00 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_min(t_stack *a)
{
	int i;
	int min;

	min = a->stack[0];
	i = -1;
	while (++i < a->len)
	{
		if (a->stack[i] < min)
			min = a->stack[i];
	}
	return (min);
}

int		get_median(t_stack *a)
{
	int i;
	int j;
	int before;
	int after;

	i = 0;
	while (i < a->len)
	{
		before = 0;
		after = 0;
		j = 0;
		while (j < a->len)
		{
			if (a->stack[j] < a->stack[i])
				before++;
			if (a->stack[j] > a->stack[i])
				after++;
			j++;
		}
		if (before - after <= 1 && before - after >= -1)
			return (a->stack[i]);
		i++;
	}
	return (a->stack[0]);
}

int		next_push(t_stack *a, int median)
{
	int i;

	i = a->len - 1;
	while (i > 0)
	{
		if (a->stack[i] < median)
		{
			return (i);
		}
		i--;
	}
	return (0);
}

void	quicksort(t_stack *a, t_stack *b)
{
	int median;

	while (a->len > 1)
	{
		median = get_median(a);
		while (median != get_min(a) || median != a->stack[a->len - 1])
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
