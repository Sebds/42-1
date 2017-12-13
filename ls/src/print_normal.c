/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:59:54 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_modulo(t_file *file, t_layout layout, int i, int newline)
{
	int count;
	int tab;

	count = 0;
	while (file)
	{
		if (count == i)
		{
			if (newline)
				ft_printf("%s\n", file->name);
			else
			{
				ft_printf("%-s", file->name);
				tab = file->name_len;
				while (tab < layout.max_name)
				{
					ft_printf("\t");
					tab += 8;
				}
			}
			return ;
		}
		file = file->next;
		count++;
	}
}

void	ft_init_dimension(t_dimension *dim, t_layout *layout, t_option *option)
{
	layout->max_name += 8 - (layout->max_name % 8);
	option->columns_temp = option->columns;
	if (option->columns == 0 || option->columns < layout->max_name)
		option->columns_temp = layout->max_name + 1;
	dim->col = (int)option->columns_temp / layout->max_name;
	while (layout->count_file % dim->col != dim->col - 1 && \
		layout->count_file % dim->col != 0)
		dim->col--;
	if (dim->col * layout->max_name >= option->columns_temp)
		dim->col--;
	dim->line = layout->count_file / dim->col;
	if (layout->count_file % dim->col)
		dim->line++;
	dim->i = 0;
	dim->j = 0;
	dim->k = 0;
}

void	ft_print_normal(t_file *file_lst, t_layout layout, t_option *option)
{
	t_file		*begin;
	t_file		*temp;
	t_dimension dim;

	ft_init_dimension(&dim, &layout, option);
	begin = file_lst;
	while (file_lst && dim.i < layout.count_file)
	{
		temp = begin;
		if ((dim.i + 1) % dim.col == 0 || file_lst->next == NULL)
			dim.newline = 1;
		else
			dim.newline = 0;
		ft_print_modulo(temp, layout, (dim.j % layout.count_file), dim.newline);
		dim.j += dim.line;
		if (dim.j >= layout.count_file)
			dim.j = ++dim.k;
		dim.i++;
		file_lst = file_lst->next;
	}
}
