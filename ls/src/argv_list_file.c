/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_list_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:55:15 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:55:15 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*ft_search_file_cur(char *file_path)
{
	t_file			*file;
	struct dirent	*data;
	DIR				*dir;

	file = ft_file_new();
	if ((dir = opendir(".")) == NULL)
		return (NULL);
	while ((data = readdir(dir)))
	{
		if (ft_strequ(data->d_name, file_path))
			ft_get_file(file, "./", data);
	}
	closedir(dir);
	return (file);
}

t_file	*ft_search_file_deep(char *trunc_file, char *trunc_path, char *path)
{
	t_file			*file;
	struct dirent	*data;
	DIR				*dir;

	trunc_file = ft_strsub(trunc_file + 1, 0, ft_strlen(trunc_file) - 1);
	trunc_path = ft_strsub(path, 0, ft_strlen(path) - ft_strlen(trunc_file));
	file = ft_file_new();
	if ((dir = opendir(trunc_path)) == NULL)
		return (NULL);
	while ((data = readdir(dir)))
	{
		if (ft_strequ(data->d_name, trunc_file))
			ft_get_file(file, trunc_path, data);
	}
	closedir(dir);
	return (file);
}

t_file	*ft_search_file(t_layout *layout, char **file_path)
{
	char			*trunc_path;
	char			*trunc_file;
	int				i;
	t_file			*list_file;
	t_file			*current;

	i = -1;
	list_file = NULL;
	while (file_path && file_path[++i] != NULL)
	{
		trunc_file = ft_strrchr(file_path[i], '/');
		trunc_path = NULL;
		if (trunc_file == NULL)
			current = ft_search_file_cur(file_path[i]);
		else
			current = ft_search_file_deep(trunc_file, trunc_path, file_path[i]);
		current->name = ft_strdup(file_path[i]);
		ft_get_layout(current, layout);
		ft_file_push_back(&list_file, current);
	}
	return (list_file);
}
