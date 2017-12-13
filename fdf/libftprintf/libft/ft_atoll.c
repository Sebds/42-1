/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/15 21:48:46 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

long long int	ft_atoll(const char *str)
{
	long long int	i;
	long long int	final_number;
	int				is_negativ;

	i = 0;
	final_number = 0;
	is_negativ = 0;
	while (str[i] >= 7 && str[i] <= 32)
		i++;
	if (str[i] == '-')
		is_negativ = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		final_number *= 10;
		final_number += str[i] - '0';
		i++;
	}
	if (is_negativ == 1)
		return (-final_number);
	else
		return (final_number);
}
