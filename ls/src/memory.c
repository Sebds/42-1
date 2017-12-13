/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:29:11 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/30 21:29:11 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_del_file_list(t_file **file_list)
{
	int	i;

	i = 0;
	while (file_list && *file_list && i++ < 5000)
	{
		free((*file_list)->name);
		free((*file_list)->owner);
		free((*file_list)->group);
		free((*file_list)->name_link);
		free(*file_list);
		*file_list = (*file_list)->next;
	}
}

void	ft_del_dir_list(t_dir **dir_list)
{
	while (dir_list && *dir_list)
	{
		free((*dir_list)->path_dir);
		free(*dir_list);
		*dir_list = (*dir_list)->next;
	}
}

void	ft_delete_date(t_date *date)
{
	free(date->future);
	free(date->less_six_monthes);
	free(date->more_six_monthes);
	free(date->year);
}
