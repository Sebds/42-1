/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:25:53 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:05:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define VISU			1
# define CHECKER_DEBUG	1

# include "libftprintf.h"

typedef struct	s_stack
{
	int			*stack;
	int			len;
	char		*line;
	int			operations;
}				t_stack;

void			quit(char *str);

int				str_is_number(char *input);
int				fits_int(char *input);
int				check_doubles(t_stack *a);

void			print_stack(t_stack *a, t_stack *b);
void			init_stack_struct(t_stack *a, t_stack *b, int argc);

void			read_instructions(t_stack *a, t_stack *b);

void			push(t_stack *input, t_stack *output);
void			swap(t_stack *input);
void			rotate(t_stack *input);
void			reverse_rotate(t_stack *input);

#endif
