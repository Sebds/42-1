/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 06:36:44 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 07:33:25 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	display_dimension(t_dimension *dim, t_env *e)
{
	e->max_len = e->max_len_save;
	e->max_len += 8 - (e->max_len % 8);
	e->term_columns_tmp = e->term_columns;
	if (e->term_columns == 0 || e->term_columns < e->max_len)
		e->term_columns_tmp = e->max_len + 1;
	(e->max_len == 0) ? e->max_len++ : 0;
	dim->col = e->term_columns_tmp / (e->max_len + 1);
	if (dim->col * e->max_len >= e->term_columns_tmp)
		dim->col--;
	e->new_line = 0;
	e->display_columns = dim->col;
	e->display_lines = dim->line;
}

void	display_reset(t_env *e)
{
	int i;

	ft_fprintf(2, CURSOR_LOAD);
	i = 0;
	while (i++ < e->term_lines)
		ft_fprintf(2, CURSOR_CLEAR_LINE""CURSOR_GO_DOWN);
	ft_fprintf(2, CURSOR_LOAD);
}

void	display(t_env *e)
{
	t_dimension dim;
	int			count;
	int			is_tab;

	display_reset(e);
	display_dimension(&dim, e);
	count = -1;
	while (e->file[++count])
	{
		ft_fprintf(2, "%s%s"RESET, e->file[count]->mode, e->file[count]->name);
		if ((count + 1) % e->display_columns == 0)
			ft_fprintf(2, "\n\r");
		else if (count == 0 && (e->max_len + 8) >= e->term_columns_tmp)
			ft_fprintf(2, "\n\r");
		else
		{
			is_tab = e->file[count]->len;
			while (is_tab < e->max_len)
			{
				ft_fprintf(2, "\t");
				is_tab += 8;
			}
		}
	}
}
