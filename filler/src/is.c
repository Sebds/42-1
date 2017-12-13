/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/05 22:20:47 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_is_champion(char board_letter, t_env *info)
{
	if (board_letter == info->letter)
		return (1);
	if (board_letter == info->letter + 21)
		return (1);
	return (0);
}

int		ft_is_challenger(char board_letter, t_env *info)
{
	if (board_letter != info->letter)
		if (board_letter != info->letter + 21)
			if (board_letter != '.')
				return (1);
	return (0);
}
