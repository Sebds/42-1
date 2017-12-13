/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_long_lo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:26:20 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/16 01:50:55 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_octal_long(unsigned long int octal, int display)
{
	unsigned long int	width_nb;
	unsigned long int	octal_bis;
	int					count;

	width_nb = 1;
	octal_bis = octal;
	while ((octal_bis /= 8) > 0)
		width_nb *= 8;
	count = 0;
	while (width_nb != 0)
	{
		count += ft_putchar_count((octal / width_nb) % 8 + '0', display);
		width_nb /= 8;
	}
	return (count);
}

void	ft_lo_get_central_len(unsigned long int lo, t_format *format)
{
	LEN = ft_put_octal_long(lo, 0);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_octal_long(va_list arg, t_format *format)
{
	unsigned long int	lo;
	int					count;

	lo = va_arg(arg, unsigned long int);
	count = 0;
	if (IS_PRECISION && PRECISION == 0 && lo == 0)
	{
		count += ft_put_blanks(WIDTH);
		if (FLAG[0] == '#')
			count += ft_putchar_count('0', 1);
		return (count);
	}
	if (lo == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_lo_get_central_len(lo, format);
	ft_octal_get_fill_left(format);
	ft_octal_get_fill_right(format);
	count += ft_octal_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_octal_long(lo, 1);
	count += ft_octal_write_right(format);
	return (count);
}
