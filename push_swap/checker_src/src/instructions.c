/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:57:56 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:25:10 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	quit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (CHECKER_DEBUG)
	{
		ft_putstr_fd("bad instruction : ", 2);
		ft_putendl_fd(str, 2);
	}
	exit(0);
}

void	check_order(t_stack *a)
{
	int i;

	i = a->len;
	while (i-- > 1)
	{
		if (a->stack[i] > a->stack[i - 1])
		{
			ft_printf("KO\n");
			if (CHECKER_DEBUG)
				ft_printf("[not sorted]\n");
			exit(0);
		}
	}
}

void	check_stacks(t_stack *a, t_stack *b)
{
	print_stack(a, b);
	check_order(a);
	if (b->len > 0)
	{
		ft_printf("KO\n");
		if (CHECKER_DEBUG)
			ft_printf("[b stack not empty]\n");
	}
	else
	{
		ft_printf("OK\n");
		if (CHECKER_DEBUG)
			ft_printf("[%d instructions]\n", a->operations);
	}
}

int		is_not_instruction(char *line)
{
	if (ft_strequ("sa", line) || ft_strequ("ss", line))
		return (0);
	else if (ft_strequ("sb", line) || ft_strequ("ss", line))
		return (0);
	else if (ft_strequ("pa", line) || ft_strequ("pb", line))
		return (0);
	else if (ft_strequ("ra", line) || ft_strequ("rr", line))
		return (0);
	else if (ft_strequ("rb", line) || ft_strequ("rr", line))
		return (0);
	else if (ft_strequ("rra", line) || ft_strequ("rrr", line))
		return (0);
	else if (ft_strequ("rrb", line) || ft_strequ("rrr", line))
		return (0);
	return (1);
}

void	read_instructions(t_stack *a, t_stack *b)
{
	while (get_next_line(0, &a->line) > 0 && ft_strlen(a->line) > 0)
	{
		if (ft_strequ("sa", a->line) || ft_strequ("ss", a->line))
			swap(a);
		if (ft_strequ("sb", a->line) || ft_strequ("ss", a->line))
			swap(b);
		if (ft_strequ("pa", a->line))
			push(b, a);
		if (ft_strequ("pb", a->line))
			push(a, b);
		if (ft_strequ("ra", a->line) || ft_strequ("rr", a->line))
			rotate(a);
		if (ft_strequ("rb", a->line) || ft_strequ("rr", a->line))
			rotate(b);
		if (ft_strequ("rra", a->line) || ft_strequ("rrr", a->line))
			reverse_rotate(a);
		if (ft_strequ("rrb", a->line) || ft_strequ("rrr", a->line))
			reverse_rotate(b);
		if (is_not_instruction(a->line))
			quit(a->line);
		print_stack(a, b);
		free(a->line);
	}
	free(a->line);
	check_stacks(a, b);
}
