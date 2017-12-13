/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:48:11 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 15:51:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	raw_terminal(t_env *e)
{
	struct termios	terminal;
	char			*env;

	tcgetattr(STDIN_FILENO, &e->initial_term);
	tcgetattr(STDIN_FILENO, &terminal);
	terminal.c_lflag &= ~(ECHO | ICANON);
	terminal.c_oflag &= ~(OPOST);
	terminal.c_cc[VMIN] = 1;
	terminal.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &terminal);
	if (!(env = getenv("TERM")))
	{
		ft_putstr_fd("ft_select: TERM env not found\n\r", 2);
		handle_default(0);
	}
	if (tgetent(NULL, env) < 0)
	{
		ft_putstr_fd("ft_select: not compatible terminal\n\r", 2);
		handle_default(0);
	}
	ft_fprintf(2, CURSOR_HIDE""CURSOR_0_0);
	ft_fprintf(2, CURSOR_ERASE""CURSOR_0_0""CURSOR_SAVE);
}

void	default_terminal(t_env *e)
{
	display_reset(g_signal_env);
	ft_fprintf(2, CURSOR_SHOW);
	e->initial_term.c_lflag |= (ECHO | ICANON);
	e->initial_term.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &e->initial_term);
}
