/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 06:21:59 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 11:12:38 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	get_term_dim(t_env *e)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	e->term_columns = w.ws_col;
	e->term_lines = w.ws_row;
	if (ttyslot() < 0)
	{
		ft_putstr_fd("ft_select: Not a terminal\n\r", 2);
		handle_default(0);
	}
}
