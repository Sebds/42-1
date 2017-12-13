/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fits_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:36:48 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:53:35 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_fits_int(char *input)
{
	if (!input || !*input)
		return (0);
	if (ft_strlen(input) > 11)
		return (0);
	if (ft_atoll(input) > (long)2147483647)
		return (0);
	if (ft_atoll(input) < (long)-2147483648)
		return (0);
	return (1);
}
