/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 01:04:43 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/16 01:50:55 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int power)
{
	int total;
	int count;

	total = 1;
	count = 0;
	while (count < power)
	{
		total = total * nb;
		count++;
	}
	if (power > 0)
		return (total);
	else if (power == 0)
		return (1);
	else
		return (0);
}
