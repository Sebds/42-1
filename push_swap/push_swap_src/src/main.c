/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:59:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:07:15 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_struct(t_stack *a, t_stack *b, int argc)
{
	a->len = argc - 1;
	b->len = 0;
	a->stack = (int *)malloc(sizeof(int) * a->len);
	b->stack = (int *)malloc(sizeof(int) * a->len);
	if (!a->stack || !b->stack)
		exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	t_stack a;
	t_stack	b;
	int		i;

	if (argc < 2)
		exit(0);
	init_stack_struct(&a, &b, argc);
	i = -1;
	while (++i >= 0 && argc-- > 1)
	{
		if (str_is_number(argv[argc]) && fits_int(argv[argc]))
			a.stack[i] = ft_atoi(argv[argc]);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	check_doubles(&a);
	sort(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}
