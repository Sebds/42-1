/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 13:12:49 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:04:48 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		str_is_number(char *input)
{
	int i;

	i = 0;
	if (ft_strequ(input, "-"))
		return (0);
	if (input[i] == '-')
		i++;
	while (ft_isdigit(input[i]))
		i++;
	return ((int)ft_strlen(input) == i);
}

int		fits_int(char *input)
{
	if (ft_strlen(input) > 11)
		return (0);
	if (ft_atoll(input) > (long)2147483647)
		return (0);
	if (ft_atoll(input) < (long)-2147483648)
		return (0);
	return (1);
}

int		check_doubles(t_stack *a)
{
	int i;
	int j;

	i = -1;
	while (++i < a->len)
	{
		j = i;
		while (++j < a->len)
		{
			if (a->stack[i] == a->stack[j])
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
	}
	if (a->len == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (1);
}
