/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 06:38:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 07:31:09 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	init_env_file(t_env *e)
{
	int i;

	i = 0;
	e->file = (t_file **)ft_memalloc(sizeof(t_file *) * (e->arg_number + 1));
	e->max_len_save = 0;
	while (i < e->arg_number)
	{
		e->file[i] = (t_file *)ft_memalloc(sizeof(t_file));
		e->file[i]->name = ft_strdup(e->arg_array[i]);
		e->file[i]->len = (int)ft_strlen(e->file[i]->name);
		ft_strcpy(e->file[i]->mode, "\0");
		e->file[i]->index = i;
		e->file[i]->active = 0;
		e->file[i]->selected = 0;
		e->file[i]->deleted = 0;
		if (e->file[i]->len > e->max_len_save)
			e->max_len_save = e->file[i]->len;
		i++;
	}
	e->file[e->arg_number] = NULL;
	e->file[0]->active = 1;
}

void	init_env(t_env *e, int argc, char **argv)
{
	e->term_columns = -1;
	e->term_lines = -1;
	e->arg_number = argc;
	e->arg_array = argv;
	e->index_selected = 0;
	e->max_len = 1;
	init_env_file(e);
}
