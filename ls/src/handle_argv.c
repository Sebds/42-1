/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 04:43:26 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 04:43:26 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_handle_bad_path(t_option *option, char **bad_argv)
{
	int i;

	i = -1;
	while (bad_argv && bad_argv[++i])
	{
		opendir(bad_argv[i]);
		ft_bad_dir(bad_argv[i]);
	}
	if (bad_argv && bad_argv[0])
		option->bad_argv = 1;
	else
		option->bad_argv = 0;
}

void	ft_handle_file_list(t_option *option, char **file_argv)
{
	t_layout	layout;
	t_file		*file_list;

	ft_init_layout(&layout, NULL);
	layout.long_option = 0;
	file_list = ft_search_file(&layout, file_argv);
	ft_select_ls(file_list, layout, option, NULL);
	if (file_argv && file_argv[0])
	{
		option->newline_dir = 1;
		option->file_argv = 1;
	}
	else
	{
		option->newline_dir = 0;
		option->file_argv = 0;
	}
}

void	ft_handle_dir_list(t_option *option, char **dir_argv)
{
	t_dir	*dir_list;
	t_dir	*head;
	char	*correct_path;

	dir_list = ft_search_dir(option, dir_argv);
	head = dir_list;
	while (dir_list)
	{
		if (option->newline_dir == 1)
			ft_printf("\n");
		if (dir_argv[1] || option->file_argv || option->bad_argv)
			ft_printf("%s:\n", dir_list->path_dir);
		correct_path = ft_path(dir_list->path_dir);
		ft_ls(option, correct_path);
		free(correct_path);
		dir_list = dir_list->next;
		option->newline_dir = 1;
	}
	ft_del_dir_list(&head);
	free(dir_list);
}

char	**ft_alloc_tab(t_option *option, char **argv, int type)
{
	char	**tab;
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) == 0)
			ft_empty_argv();
		if (ft_search_argv(option, argv[i]) == type)
			count++;
	}
	if (count == 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * count + 1);
	return (tab);
}

char	**ft_create_tab_argv(t_option *option, char **argv, int type)
{
	char	**tab;
	int		i;
	int		count;

	i = -1;
	count = 0;
	tab = ft_alloc_tab(option, argv, type);
	if (tab == NULL)
		return (NULL);
	while (argv[++i])
	{
		if (ft_search_argv(option, argv[i]) == type)
		{
			tab[count] = argv[i];
			count++;
		}
	}
	tab[count] = NULL;
	ft_sort_tab(tab);
	return (tab);
}
