/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:56:11 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/22 18:56:11 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# define FILLIT_DEBUG 0

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct		s_split
{
	char			array[26][21];
}					t_split;

typedef struct		s_split_b
{
	char			b[5][5];
}					t_split_b;

typedef struct		s_tetro
{
	char			letter;
	int				shape[4][4];
	struct s_tetro	*next;
}					t_tetro;

int					ft_quit(char *reason);

t_split				ft_split_input(char *full_fd);
char				*ft_read_input(int fd);

t_tetro				*ft_place_up_and_left(t_split split_input);

void				ft_check_split_block(char split_block[5][5]);
void				ft_shape(t_tetro *all_tetros, char split_b[5][5], int i);

char				**ft_map(int size);
void				ft_print_map(char **map, int size);
void				ft_clean_map(char **map, int size, char letter);
int					ft_valid_map(char **map, int size, char letter);
void				ft_put_tetro(char **map, int size, t_tetro *tetro, int pos);

char				**ft_backtracking(char **map, int size, t_tetro *t, char l);

#endif
