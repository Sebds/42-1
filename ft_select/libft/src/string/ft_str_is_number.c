/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:36:48 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:53:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_number(char *input)
{
	int i;

	if (!input || !*input)
		return (0);
	i = 0;
	if (ft_strequ(input, "-"))
		return (0);
	if (input[i] == '-')
		i++;
	while (ft_isdigit(input[i]))
		i++;
	return ((int)ft_strlen(input) == i);
}
