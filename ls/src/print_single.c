/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:59:54 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_single(t_file *file_lst, t_option *option)
{
	while (file_lst)
	{
		if (file_lst->name == NULL)
		{
			ft_bad_dir("");
			return ;
		}
		if (ft_handle_dotfile(option, file_lst->name))
			ft_printf("%s\n", file_lst->name);
		file_lst = file_lst->next;
	}
}
