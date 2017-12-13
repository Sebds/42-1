/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:59:54 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_get_layout(t_file *file, t_layout *layout)
{
	layout->total_block += file->block;
	layout->count_file += 1;
	if (layout->max_link < file->link_len)
		layout->max_link = file->link_len;
	if (layout->max_owner < file->owner_len)
		layout->max_owner = file->owner_len;
	if (layout->max_group < file->group_len)
		layout->max_group = file->group_len;
	if (layout->max_size < file->size_len)
		layout->max_size = file->size_len;
	if (layout->max_name < file->name_len)
		layout->max_name = file->name_len;
	if (layout->max_minor < file->minor_len)
		layout->max_minor = file->minor_len;
	if (layout->max_major < file->major_len)
		layout->max_major = file->major_len;
	if (file->minor + file->major > 0)
		if (layout->max_size < layout->max_major + layout->max_minor + 1)
			layout->max_size = layout->max_major + layout->max_minor + 1;
}

void	ft_get_upid(t_file *file, struct stat buf)
{
	if (getpwuid(buf.st_uid))
		file->owner = ft_strdup(getpwuid(buf.st_uid)->pw_name);
	else
		file->owner = ft_itoa(buf.st_uid);
	if (getgrgid(buf.st_gid))
		file->group = ft_strdup(getgrgid(buf.st_gid)->gr_name);
	else
		file->group = ft_itoa(buf.st_gid);
}

void	ft_get_linked_name(t_file *file, char *path_file)
{
	char *buf;

	if ((file->perm & S_IFMT) == S_IFLNK)
	{
		buf = ft_strnew(1024);
		if (readlink(path_file, buf, 1024) != -1)
			file->name_link = buf;
	}
}

void	ft_get_file_len(t_file *file)
{
	file->link_len = ft_intlen(file->link);
	file->owner_len = (int)ft_strlen(file->owner);
	file->group_len = (int)ft_strlen(file->group);
	file->size_len = ft_intlen(file->size);
	file->minor_len = ft_intlen(file->minor);
	file->major_len = ft_intlen(file->major);
	file->name_len = (int)ft_strlen(file->name);
}

void	ft_get_file(t_file *file, char *path_dir, struct dirent *data)
{
	char			*path_file;
	struct stat		buf;

	path_file = ft_strjoin(path_dir, data->d_name);
	if (lstat(path_file, &buf) == -1)
	{
		file->name = NULL;
		return ;
	}
	file->perm = buf.st_mode;
	file->link = buf.st_nlink;
	ft_get_upid(file, buf);
	file->size = buf.st_size;
	file->minor = ft_minor(buf.st_rdev);
	file->major = ft_major(buf.st_rdev);
	file->date = buf.st_mtimespec.tv_sec;
	file->name = ft_strnew(ft_strlen(data->d_name));
	ft_strcpy(file->name, data->d_name);
	file->block = buf.st_blocks;
	ft_get_linked_name(file, path_file);
	ft_get_file_len(file);
	free(path_file);
}
