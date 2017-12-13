/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:59:54 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_init_option(t_option *option)
{
	struct winsize	w;

	option->dot_files = 0;
	option->long_option = 0;
	option->reverse = 0;
	option->sort_time = 0;
	option->recursive = 0;
	option->single = 0;
	if (isatty(1))
	{
		ioctl(0, TIOCGWINSZ, &w);
		option->columns = w.ws_col;
	}
	else
	{
		option->single = 1;
		option->columns = 0;
	}
	option->count_args = 1;
}

void	ft_init_layout(t_layout *layout, char *path)
{
	layout->max_link = 0;
	layout->max_owner = 0;
	layout->max_group = 0;
	layout->max_size = 0;
	layout->max_name = 0;
	layout->max_minor = 0;
	layout->max_major = 0;
	layout->total_block = 0;
	layout->count_file = 0;
	layout->long_option = 1;
	layout->path = path;
	layout->newline_dir = 0;
}

void	ft_init_var(t_var *var)
{
	var->dir = NULL;
	var->path_file = NULL;
	var->data = NULL;
}
