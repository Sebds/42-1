/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:42:59 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/13 22:31:02 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libftprintf/includes/libftprintf.h"
# include "../libmlx/mlx.h"

# define FILLER_DEBUG 0
# define ENABLE_VISUALIZER 0
# define MAX_WIN_HEIGHT 1000

typedef struct		s_env
{
	char			letter;

	int				b_line;
	int				b_col;
	char			**board;

	int				p_line;
	int				p_col;
	char			**piece;

	int				got_char;
	int				got_board;

	int				count;

	int				distance;

	int				init_mlx;

	int				height;
	int				height_scale;

	int				width;
	int				width_scale;

	int				total_champion;
	int				total_challenger;

	void			*mlx;
	void			*win;

	int				*frame;
	void			*frame_addr;
	int				**split_frame;

	int				*black;
	void			*black_addr;

	int				x;
	int				y;
}					t_env;

void				ft_free_tab(char **tab);

int					ft_is_number(char *str);

int					ft_tab_lines(char **tab);

void				ft_check_line(char *line, int len);

void				ft_check_tab(char **tab);

int					ft_get_distance(t_env *info, int i, int j);

void				ft_place_next_to_challenger(t_env *info);

void				ft_evil_strategy_distance(t_env *info);

void				ft_get_id(t_env *info, char **line);
void				ft_get_board(t_env *info, char **line);
void				ft_get_piece(t_env *info, char **line);

int					ft_is_champion(char board_letter, t_env *info);
int					ft_is_challenger(char board_letter, t_env *info);

int					ft_close_win(int keycode, t_env *info);
void				ft_quit(char *reason, t_env *info);
int					ft_visualizer(t_env *info);

void				ft_free_memory(t_env *info);

int					ft_can_place(t_env *info, int x, int y, int count);

void				ft_reset_visualizer(t_env *info);
void				ft_update_visualizer(t_env *info, int x, int y);
void				ft_display_score(t_env *info);

void				ft_init_frame(t_env *info);
void				ft_scale(t_env *info);
void				ft_init_visualizer(t_env *info);

#endif
