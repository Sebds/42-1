/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:49:04 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 15:35:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_env	*g_signal_env;

int		main(int argc, char **argv)
{
	char			buf[1024];
	t_key			*key;
	t_env			*e;

	if (argc < 2)
		return (0);
	e = (t_env *)ft_memalloc(sizeof(t_env));
	g_signal_env = e;
	raw_terminal(e);
	init_env(e, --argc, ++argv);
	e->count = 0;
	while (1)
	{
		handle_signal();
		get_term_dim(e);
		file_mode(e);
		handle_resize(0);
		ft_memset((void *)buf, 0, 1024);
		read(STDIN_FILENO, buf, 1024);
		key = key_get(buf);
		change_selection(e, key);
		key_delete(&key);
	}
}
