/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 06:53:44 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 15:40:20 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "libftprintf.h"
# include "key_codes.h"
# include <signal.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

# define TRUE	1
# define FALSE	0

# define CURSOR_LOAD		"\x1B[u"
# define CURSOR_SAVE		"\x1B[s"
# define CURSOR_ERASE		"\x1B[J"
# define CURSOR_CLEAR_LINE	"\x1B[K"
# define CURSOR_GO_DOWN		"\x1B[B"
# define CURSOR_HIDE		"\x1b[?25l"
# define CURSOR_SHOW		"\x1b[?25h"
# define CURSOR_0_0			"\x1B[0;0H"
# define CURSOR_UNDERLINE	"\x1B[4;m"
# define CURSOR_NEGATIVE	"\x1B[7;m"

typedef struct	s_file
{
	int			index;
	char		*name;
	int			len;
	char		mode[15];
	int			active;
	int			selected;
	int			deleted;
}				t_file;

typedef struct	s_dimension
{
	int			col;
	int			line;
	int			put_newline;
}				t_dimension;

typedef struct	s_env
{
	int				term_columns;
	int				term_columns_tmp;
	int				term_lines;

	int				arg_number;
	char			**arg_array;

	t_file			**file;

	int				max_len;
	int				max_len_save;

	int				display_columns;
	int				display_lines;
	int				display_pad;

	int				new_line;
	int				count;
	int				index_selected;

	struct termios	initial_term;
}				t_env;

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

extern t_env	*g_signal_env;

# endif

void			init_env(t_env *e, int argc, char **argv);

/*
**	*******
**	DISPLAY
**	*******
*/

void			display_dimension(t_dimension *dim, t_env *e);
void			display_reset(t_env *e);
void			display(t_env *e);

/*
**	***
**	KEY
**	***
*/

t_key			*key_new(t_key_type type, char *value);
void			key_delete(t_key **akey);
t_key			*key_get(char *buff);

t_bool			key_is_up(char *buff);
t_bool			key_is_down(char *buff);
t_bool			key_is_left(char *buff);
t_bool			key_is_right(char *buff);

t_bool			key_is_space(char *buff);
t_bool			key_is_return(char *buff);
t_bool			key_is_escape(char *buff);
t_bool			key_is_backspace(char *buff);
t_bool			key_is_delete(char *buff);

/*
**	*********
**	SELECTION
**	*********
*/

void			file_mode(t_env *e);

void			move_cursor_up(t_env *e);
void			move_cursor_down(t_env *e);
void			move_cursor_left(t_env *e);
void			move_cursor_right(t_env *e);

void			select_file(t_env *e);
void			delete_file(t_env *e);

void			handle_ret(t_env *e);
void			change_selection(t_env *e, t_key *key);

/*
**	******
**	SIGNAL
**	******
*/

void			handle_default(int key);
void			handle_stop(int key);
void			handle_cont(int key);
void			handle_resize(int key);
void			handle_signal(void);

/*
**	********
**	TERMINAL
**	********
*/

void			get_term_dim(t_env *e);
void			raw_terminal(t_env *e);
void			default_terminal(t_env *e);

#endif
