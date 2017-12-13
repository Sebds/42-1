/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:43:41 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_display_big_nb_fd(unsigned int nb, int fd)
{
	unsigned int width_nb;
	unsigned int nb_bis;

	width_nb = 1;
	nb_bis = nb;
	while ((nb_bis /= 10) > 0)
	{
		width_nb *= 10;
	}
	while (width_nb != 0)
	{
		ft_putchar_fd(((nb / width_nb) % 10 + '0'), fd);
		width_nb /= 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_display_big_nb_fd(n, fd);
}
