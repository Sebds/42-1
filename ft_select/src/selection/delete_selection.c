/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 06:38:30 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 07:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	delete_file(t_env *e)
{
	t_file	**new;
	int		i;
	int		j;

	(e->arg_number == 1) ? handle_default(0) : 0;
	new = (t_file **)ft_memalloc(sizeof(t_file *) * (e->arg_number + 2));
	i = -1;
	j = 0;
	while (++i < e->arg_number)
	{
		if (i != e->index_selected)
			new[j++] = e->file[i];
		else
		{
			free(e->file[i]->name);
			e->file[i]->name = NULL;
			free(e->file[i]);
			e->file[i] = NULL;
		}
	}
	e->file[e->arg_number] = NULL;
	e->file[e->arg_number - 1] = NULL;
	e->arg_number--;
	free(e->file);
	e->file = new;
}
