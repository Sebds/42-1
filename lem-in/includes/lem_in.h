/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 00:38:44 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 23:04:01 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libftprintf/includes/libftprintf.h"

# define LEM_IN_DEBUG	0

# define LEAKS_TIME		0

# define MAX_ITE		1000000000

typedef struct		s_room
{
	char			*name;
}					t_room;

typedef struct		s_pos
{
	int				num;
	int				current_room;
	struct s_pos	*next;
}					t_pos;

typedef struct		s_ant
{
	char			*ants_line;
	char			*rooms_line;
	char			*pipes_line;

	int				bloc;

	int				got_rooms;
	int				got_pipes;

	char			**split_ants;
	char			**split_rooms;
	char			**split_pipes;

	int				ant_number;
	int				rooms_number;
	int				pipes_number;

	struct s_room	*matrix;
	int				start_index;
	int				end_index;

	int				**pipes;

	int				*hist;
	int				*shortest_path;
	int				shortest_len;
	int				*occupation;

	int				min_steps;

	struct s_pos	*pos;

	int				ite;
}					t_ant;

/*
**	DEAD_ENDS.c
*/

void				ft_check_dead_ends(t_ant *ant);
void				ft_check_double_rooms(t_ant *ant);

/*
**	GET_INPUT.c
*/

void				ft_read_input(t_ant *ant);

/*
**	MATRIX_PIPES.c
*/

int					ft_search_matrix_index(t_ant *ant, char *str);
void				ft_fill_pipes(t_ant *ant);
void				ft_matrix_pipes(t_ant *ant);

/*
**	MATRIX_ROOMS.c
*/

char				*ft_get_room_name(char *str);
void				ft_matrix_rooms(t_ant *ant);

/*
**	NEXT_ROOM.c
*/

int					ft_next_room(int current_room, t_ant *ant);
int					ft_next_room_is_free(int current_room, t_ant *ant);
char				*ft_next_room_name(int current_room, t_ant *ant);
void				ft_register_ant(t_pos *pos, t_ant *ant);

/*
**	PARSE.c
*/

void				ft_check_l_and_commands(t_ant *ant);
void				ft_get_ant_number(t_ant *ant);
void				ft_get_rooms_pipes_number(t_ant *ant);
void				ft_parse(t_ant *ant);

/*
**	PATTERN.c
*/

int					ft_room_pattern(char *str);
int					ft_comment_pattern(char *str);
int					ft_pipe_pattern(char *str);

/*
**	POSITIONS.c
*/

t_pos				*ft_new_pos(void);
void				ft_pos_push_back(t_pos **list, t_pos *cur);
t_pos				*ft_create_pos(t_ant *ant);

/*
**	PRINT.c
*/

void				ft_print_occupation(t_ant *ant);
void				ft_move_ants(t_ant *ant, t_pos *pos);
int					ft_all_at_end(t_pos *pos, int start_index);
void				ft_one_step(t_ant *ant);
void				ft_init_print(t_ant *ant);

/*
**	SOLVE_HISTORY.c
*/

int					ft_is_not_in_hist(int index, t_ant *ant);
void				ft_push_hist(int *hist, int size, int index);
void				ft_pop_hist(int *hist, int size);
void				ft_dup_step_hist(t_ant *ant);

/*
**	SOLVE_TOOLS.c
*/

int					ft_count_shortest_steps(t_ant *ant);
int					ft_count_steps(t_ant *ant);
void				ft_print_steps(t_ant *ant);
void				ft_print_instructions(t_ant *ant);
void				ft_init_backtrack(t_ant *ant);

/*
**	SOLVE.c
*/

void				ft_print_solution(t_ant *ant);
void				ft_solve(t_ant *ant, int start);

/*
**	TOOLS.c
*/

void				ft_quit(char *reason);
int					ft_is_number(char *str);
int					ft_tab_lines(char **tab);
void				ft_free_tab(char **tab);

#endif
