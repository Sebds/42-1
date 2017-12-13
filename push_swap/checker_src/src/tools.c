/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 13:12:49 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:04:37 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack *a, t_stack *b)
{
	int i;

	a->operations++;
	if (VISU == 0)
		return ;
	if (a->len > b->len)
		i = a->len;
	else
		i = b->len;
	ft_printf("\x1B[31m%s\x1B[0m\n", a->line);
	while (--i >= 0)
	{
		if (i < a->len)
			ft_printf("\x1B[32mA\x1B[0m[%3d] : %11d\t", i, a->stack[i]);
		else
			ft_printf("%20s\t", "");
		if (i < b->len)
			ft_printf("\x1B[33mB\x1B[0m[%3d] : %11d", i, b->stack[i]);
		ft_printf("\n");
	}
	ft_printf("\n\n\n");
	usleep(50000);
}

void	init_stack_struct(t_stack *a, t_stack *b, int argc)
{
	a->len = argc - 1;
	b->len = 0;
	a->operations = 0;
	a->stack = (int *)malloc(sizeof(int) * a->len);
	b->stack = (int *)malloc(sizeof(int) * a->len);
	if (!a->stack || !b->stack)
		exit(EXIT_FAILURE);
}
