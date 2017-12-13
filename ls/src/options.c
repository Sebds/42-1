/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:16:40 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/30 21:41:58 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_fill_option(t_option *option, char c)
{
	(c == 'a') ? (option->dot_files = 1) : 0;
	(c == 'r') ? (option->reverse = 1) : 0;
	(c == 't') ? (option->sort_time = 1) : 0;
	(c == 'R') ? (option->recursive = 1) : 0;
	if (c == '1')
	{
		option->single = 1;
		option->long_option = 0;
	}
	if (c == 'l')
	{
		option->long_option = 1;
		option->single = 0;
	}
	if (!getuid())
		option->dot_files = 1;
}

void	ft_get_option(t_option *option, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	ft_init_option(option);
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			ft_empty_argv();
		if (argv[i][0] == '-' && argv[i][1])
		{
			j = 1;
			while (argv[i][j])
			{
				ft_fill_option(option, argv[i][j]);
				ft_usage(argv[i][j], argv[i][j + 1]);
				j++;
			}
			option->count_args++;
			if (ft_strequ("--", argv[i]))
				break ;
		}
		else
			break ;
	}
}
