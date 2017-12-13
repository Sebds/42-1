/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:48:44 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/29 01:28:29 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	handle_default(int key)
{
	(void)key;
	default_terminal(g_signal_env);
	exit(0);
}

void	handle_stop(int key)
{
	struct termios	term;
	char			tmp[2];

	(void)key;
	if (isatty(STDIN_FILENO) == 1)
	{
		default_terminal(g_signal_env);
		tcgetattr(STDIN_FILENO, &term);
		tmp[0] = term.c_cc[VSUSP];
		tmp[1] = 0;
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDIN_FILENO, TIOCSTI, tmp);
	}
}

void	handle_cont(int key)
{
	(void)key;
	raw_terminal(g_signal_env);
	display_reset(g_signal_env);
	handle_resize(0);
	signal(SIGCONT, handle_cont);
}

void	handle_resize(int key)
{
	t_dimension	dim;
	int			argc;
	int			ratio;

	(void)key;
	display_dimension(&dim, g_signal_env);
	argc = g_signal_env->arg_number;
	ratio = (g_signal_env->term_columns - 8) / (g_signal_env->max_len + 1);
	ratio *= g_signal_env->term_lines;
	get_term_dim(g_signal_env);
	if (ratio < argc)
	{
		display_reset(g_signal_env);
		ft_fprintf(2, "ERROR\n\rPLEASE\n\rENLARGE\n\rTERMINAL\r\n"CURSOR_LOAD);
	}
	else
		display(g_signal_env);
}

void	handle_signal(void)
{
	signal(SIGTSTP, handle_stop);
	signal(SIGCONT, handle_cont);
	signal(SIGWINCH, handle_resize);
	signal(SIGABRT, handle_default);
	signal(SIGALRM, handle_default);
	signal(SIGBUS, handle_default);
	signal(SIGFPE, handle_default);
	signal(SIGHUP, handle_default);
	signal(SIGILL, handle_default);
	signal(SIGINT, handle_default);
	signal(SIGPIPE, handle_default);
	signal(SIGQUIT, handle_default);
	signal(SIGSEGV, handle_default);
	signal(SIGTERM, handle_default);
	signal(SIGPROF, handle_default);
	signal(SIGSYS, handle_default);
	signal(SIGTERM, handle_default);
	signal(SIGTRAP, handle_default);
	signal(SIGURG, handle_default);
	signal(SIGXCPU, handle_default);
	signal(SIGXFSZ, handle_default);
}
