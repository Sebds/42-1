/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 22:39:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/16 01:50:55 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprime(int nb)
{
	int count;
	int is_not_prime;

	is_not_prime = 0;
	count = nb - 1;
	while (count > 1)
	{
		if (nb % count == 0)
			is_not_prime = 1;
		count--;
	}
	if ((is_not_prime) || (nb <= 0) || (nb == 1))
		return (0);
	else
		return (1);
}
