/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:59:54 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_handle_dotfile(t_option *option, char *name)
{
	if ((name[0] == '.' && option->dot_files))
		return (1);
	if (name[0] != '.')
		return (1);
	return (0);
}

void	ft_handle_recursive(t_file *file_lst, t_option *option, char *path_dir)
{
	char	*new_path_dir;
	char	*correct_new_path_dir;

	while (file_lst)
	{
		if ((file_lst->perm & S_IFMT) == S_IFDIR)
		{
			if (file_lst->name && ft_allow_recursive(file_lst->name))
			{
				new_path_dir = ft_strjoin(path_dir, file_lst->name);
				ft_printf("\n%s:\n", new_path_dir);
				correct_new_path_dir = ft_path(new_path_dir);
				ft_ls(option, correct_new_path_dir);
				free(new_path_dir);
				free(correct_new_path_dir);
			}
		}
		file_lst = file_lst->next;
	}
}
