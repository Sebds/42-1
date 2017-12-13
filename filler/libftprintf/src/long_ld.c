/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:13 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/01 21:02:13 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_display_long(unsigned long int nb, int display)
{
	int					count;
	unsigned long int	width_nb;
	unsigned long int	nb_bis;

	width_nb = 1;
	nb_bis = nb;
	count = 0;
	while ((nb_bis /= 10) > 0)
		width_nb *= 10;
	while (width_nb != 0)
	{
		count += ft_putchar_count((nb / width_nb) % 10 + '0', display);
		width_nb /= 10;
	}
	return (count);
}

int		ft_put_long(long int nb, int display, t_format *format)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		IS_NEGATIVE = 1;
		nb = -nb;
	}
	else
		IS_NEGATIVE = 0;
	return (count += ft_display_long(nb, display));
}

void	ft_long_get_central_len(long int ld, t_format *format)
{
	LEN = ft_put_long(ld, 0, format);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_long(va_list arg, t_format *format)
{
	long int	ld;
	int			count;

	ld = va_arg(arg, long int);
	if (IS_PRECISION && PRECISION == 0 && ld == 0)
		return (ft_put_blanks(WIDTH));
	ft_init_len_count(format);
	ft_long_get_central_len(ld, format);
	ft_int_get_fill_left(format);
	ft_int_get_fill_right(format);
	count = 0;
	count += ft_int_write_left(format);
	count += ft_put_precision(format);
	count += ft_put_long(ld, 1, format);
	count += ft_int_write_right(format);
	return (count);
}