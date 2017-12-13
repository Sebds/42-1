/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:28:34 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:28:34 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_search_current_dir(char *argv)
{
	struct dirent	*data;
	DIR				*dir;

	if (!(dir = opendir(".")))
		return (-1);
	while ((data = readdir(dir)))
	{
		if (ft_strcmp(data->d_name, argv) == 0)
		{
			closedir(dir);
			return (2);
		}
	}
	closedir(dir);
	return (1);
}

int		ft_search_deep_dir(char *trunc_file, char *trunc_path, char *argv)
{
	DIR				*dir;
	struct dirent	*data;

	trunc_file = ft_strsub(trunc_file + 1, 0, ft_strlen(trunc_file) - 1);
	trunc_path = ft_strsub(argv, 0, ft_strlen(argv) - ft_strlen(trunc_file));
	if (!(dir = opendir(trunc_path)))
		return (1);
	while ((data = readdir(dir)))
	{
		if (ft_strcmp(data->d_name, trunc_file) == 0)
		{
			closedir(dir);
			return (2);
		}
	}
	closedir(dir);
	return (1);
}

int		ft_search_argv(t_option *option, char *argv)
{
	char			*truncated_path;
	char			*truncated_file;
	t_var			var;
	char			*buf;

	truncated_path = NULL;
	if ((var.dir = opendir(argv)))
	{
		closedir(var.dir);
		buf = ft_strnew(1024);
		if (readlink(argv, buf, 1024) != -1 && option->long_option)
			return (2);
		return (3);
	}
	else
	{
		if (ft_strequ(strerror(errno), "Permission denied"))
			return (1);
		truncated_file = ft_strrchr(argv, '/');
		if (truncated_file == NULL)
			return (ft_search_current_dir(argv));
		else
			return (ft_search_deep_dir(truncated_file, truncated_path, argv));
	}
}

void	ft_sort_tab(char **tab)
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}
