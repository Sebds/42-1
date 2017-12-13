/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 06:04:18 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 06:59:00 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	file_mode(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->arg_number)
	{
		e->file[i]->active = 0;
		e->file[i]->mode[0] = '\0';
		if (i == e->index_selected)
		{
			e->file[i]->active = 1;
			ft_strcat(e->file[i]->mode, CURSOR_UNDERLINE);
		}
		if (e->file[i]->selected == 1)
		{
			ft_strcat(e->file[i]->mode, CURSOR_NEGATIVE);
		}
	}
}
