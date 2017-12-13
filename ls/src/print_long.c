/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/19 19:30:36 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_long_option_file(t_file *file, t_layout *layout)
{
	int type;

	ft_print_permission(file, layout);
	ft_printf("%*d", layout->max_link + 1, file->link);
	ft_printf(" %-*s", layout->max_owner, file->owner);
	ft_printf("  %-*s", layout->max_group, file->group);
	type = (file->perm & S_IFMT);
	if ((type == S_IFBLK || type == S_IFCHR))
	{
		ft_printf(" %*d, ", layout->max_minor, file->minor);
		ft_printf("%*d", layout->max_major, file->major);
	}
	else
		ft_printf("%*lld", layout->max_size + 2, file->size);
	ft_print_date(file);
	ft_printf(" %s", file->name);
	if ((file->perm & S_IFMT) == S_IFLNK)
		ft_printf(" -> %s", file->name_link);
	ft_printf("\n");
}

void	ft_print_long_option(t_file *list, t_layout layout, t_option *option)
{
	if (layout.long_option && list)
		ft_printf("total %lld\n", layout.total_block);
	while (list)
	{
		if (list->name == NULL)
		{
			ft_bad_dir("");
			return ;
		}
		if (ft_handle_dotfile(option, list->name))
			ft_print_long_option_file(list, &layout);
		list = list->next;
	}
}
