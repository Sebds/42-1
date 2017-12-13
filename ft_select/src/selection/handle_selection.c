/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 06:37:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 15:47:18 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	handle_ret(t_env *e)
{
	int i;

	display_reset(e);
	i = 0;
	default_terminal(e);
	while (i < e->arg_number)
	{
		if (e->file[i]->selected == 1)
			ft_printf("\"%s\" ", e->file[i]->name);
		i++;
	}
	ft_printf("\r\n");
	exit(0);
}

void	change_selection(t_env *e, t_key *key)
{
	if (key->type == KEY_CODE_UP)
		move_cursor_up(e);
	else if (key->type == KEY_CODE_DOWN)
		move_cursor_down(e);
	else if (key->type == KEY_CODE_RIGHT)
		move_cursor_right(e);
	else if (key->type == KEY_CODE_LEFT)
		move_cursor_left(e);
	else if (key->type == KEY_CODE_SPACE)
		select_file(e);
	else if (key->type == KEY_CODE_BKSPACE || key->type == KEY_CODE_DELETE)
	{
		delete_file(e);
		if (e->index_selected == e->arg_number)
			move_cursor_right(e);
	}
	else if (key->type == KEY_CODE_ESCAPE)
		handle_default(0);
	else if (key->type == KEY_CODE_RET)
		handle_ret(e);
}
