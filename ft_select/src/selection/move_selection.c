/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 06:05:03 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 06:59:56 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	move_cursor_up(t_env *e)
{
	if (e->index_selected - e->display_columns >= 0)
		e->index_selected -= e->display_columns;
}

void	move_cursor_down(t_env *e)
{
	if (e->index_selected + e->display_columns < e->arg_number)
		e->index_selected += e->display_columns;
}

void	move_cursor_right(t_env *e)
{
	e->index_selected++;
	if (e->index_selected >= e->arg_number)
		e->index_selected = 0;
}

void	move_cursor_left(t_env *e)
{
	e->index_selected--;
	if (e->index_selected < 0)
		e->index_selected = e->arg_number - 1;
}

void	select_file(t_env *e)
{
	if (e->file[e->index_selected]->selected)
		e->file[e->index_selected]->selected = 0;
	else
		e->file[e->index_selected]->selected = 1;
}
