/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:59:54 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*ft_file_new(void)
{
	t_file	*new_file;

	if (!(new_file = (t_file *)malloc(sizeof(t_file))))
		return (ft_file_new());
	new_file->perm = 0;
	new_file->link = 0;
	new_file->link_len = 1;
	new_file->owner = NULL;
	new_file->owner_len = 0;
	new_file->group = NULL;
	new_file->group_len = 0;
	new_file->size = 0;
	new_file->size_len = 1;
	new_file->minor = 0;
	new_file->minor_len = 1;
	new_file->major = 0;
	new_file->major_len = 1;
	new_file->date = 0;
	new_file->name_link = NULL;
	new_file->name_len = 0;
	new_file->block = 0;
	new_file->next = NULL;
	return (new_file);
}

t_dir	*ft_dir_new(void)
{
	t_dir	*new_dir;

	if (!(new_dir = (t_dir *)malloc(sizeof(t_dir))))
		return (ft_dir_new());
	new_dir->path_dir = NULL;
	new_dir->date = 0;
	new_dir->next = NULL;
	return (new_dir);
}

void	ft_file_push_back(t_file **list, t_file *cur)
{
	if (!list)
		return ;
	while (*list)
		list = &(*list)->next;
	*list = cur;
}

void	ft_dir_push_back(t_dir **list, t_dir *cur)
{
	if (!list)
		return ;
	while (*list)
		list = &(*list)->next;
	*list = cur;
}
