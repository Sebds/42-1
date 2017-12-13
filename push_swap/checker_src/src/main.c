/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:59:39 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:06:09 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check(t_stack *a, t_stack *b)
{
	check_doubles(a);
	read_instructions(a, b);
	free(a->stack);
	free(b->stack);
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
	check(&a, &b);
	return (0);
}
