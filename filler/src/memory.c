/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:48:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/06 21:43:21 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_free_memory(t_env *info)
{
	int i;

	i = -1;
	while (++i < info->b_line)
	{
		free(info->board[i]);
	}
	free(info->board);
	info->board = NULL;
	i = -1;
	while (++i < info->p_line)
	{
		free(info->piece[i]);
	}
	free(info->piece);
	info->piece = NULL;
}
