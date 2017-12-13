/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/03 18:37:29 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_select_ls(t_file *list, t_layout layout, t_option *optn, char *path)
{
	ft_sort_file(&list, 'n');
	if (optn->sort_time)
		ft_sort_file(&list, 't');
	if (optn->reverse)
		ft_file_reverse(&list);
	if (optn->long_option)
		ft_print_long_option(list, layout, optn);
	else if (optn->single)
		ft_print_single(list, optn);
	else
		ft_print_normal(list, layout, optn);
	if (optn->recursive && path)
		ft_handle_recursive(list, optn, path);
	ft_del_file_list(&list);
	free(list);
}

void	ft_ls(t_option *option, char *path_dir)
{
	t_file			*file_lst;
	t_file			*file_cur;
	t_layout		layout;
	t_var			var;

	file_lst = NULL;
	ft_init_var(&var);
	if ((var.dir = opendir(path_dir)) == NULL)
		return (ft_bad_dir(path_dir));
	ft_init_layout(&layout, path_dir);
	while ((var.data = readdir(var.dir)))
	{
		if (ft_handle_dotfile(option, var.data->d_name))
		{
			file_cur = ft_file_new();
			ft_get_file(file_cur, path_dir, var.data);
			ft_get_layout(file_cur, &layout);
			if (file_cur->name != NULL)
				ft_file_push_back(&file_lst, file_cur);
		}
	}
	ft_select_ls(file_lst, layout, option, path_dir);
	closedir(var.dir);
}

void	ft_deal_with_argv(t_option *option, char **argv)
{
	char		**bad_argv;
	char		**file_argv;
	char		**dir_argv;

	bad_argv = ft_create_tab_argv(option, argv, 1);
	file_argv = ft_create_tab_argv(option, argv, 2);
	dir_argv = ft_create_tab_argv(option, argv, 3);
	ft_handle_bad_path(option, bad_argv);
	ft_handle_file_list(option, file_argv);
	ft_handle_dir_list(option, dir_argv);
}

int		main(int argc, char **argv)
{
	t_option	option;
	char		**cur;

	if (argc < 1)
		ft_usage('\0', '\0');
	cur = (char **)malloc(2 * sizeof(char *));
	if (cur == NULL)
		return (0);
	cur[0] = ft_strdup(".");
	cur[1] = NULL;
	ft_get_option(&option, argc, argv);
	(void)argc;
	argv += option.count_args;
	if (!*argv)
		ft_handle_dir_list(&option, cur);
	else
		ft_deal_with_argv(&option, argv);
	free(cur[0]);
	free(cur);
	return (1);
}
