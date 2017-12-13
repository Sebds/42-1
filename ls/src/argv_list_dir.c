/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_list_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:58:46 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:58:46 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_select_sort_dir(t_option *option, t_dir **dir_list)
{
	ft_sort_dir(dir_list, 'n');
	if (option->sort_time)
		ft_sort_dir(dir_list, 't');
	if (option->reverse)
		ft_dir_reverse(dir_list);
}

void	ft_search_dir_info(t_dir *dir, t_var var, char *dir_path)
{
	char *join_path;

	join_path = ft_strjoin(dir_path, "/.");
	if (lstat(join_path, &var.buf) != -1)
	{
		free(join_path);
		dir->date = var.buf.st_mtimespec.tv_sec;
		dir->path_dir = ft_strnew(ft_strlen(dir_path + 2));
		ft_strcpy(dir->path_dir, dir_path);
	}
}

t_dir	*ft_search_dir(t_option *option, char **dir_path)
{
	t_var			var;
	t_dir			*cur_dir;
	t_dir			*dir_list;

	var.i = -1;
	dir_list = NULL;
	while (dir_path && dir_path[++var.i])
	{
		if ((var.dir = opendir(dir_path[var.i])))
		{
			var.data = NULL;
			while ((var.data = readdir(var.dir)))
			{
				if (ft_strequ(var.data->d_name, "."))
				{
					cur_dir = ft_dir_new();
					ft_search_dir_info(cur_dir, var, dir_path[var.i]);
					ft_dir_push_back(&dir_list, cur_dir);
				}
			}
			closedir(var.dir);
		}
	}
	ft_select_sort_dir(option, &dir_list);
	return (dir_list);
}
