/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:26:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:12:45 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf.h"

typedef struct	s_stack
{
	int			*stack;
	int			len;
	int			stop;
}				t_stack;

int				str_is_number(char *input);
int				fits_int(char *input);
int				check_doubles(t_stack *a);

void			push(t_stack *input, t_stack *output);
void			swap(t_stack *input);
void			rotate(t_stack *input);
void			reverse_rotate(t_stack *input);

void			sort(t_stack *a, t_stack *b);
void			rotate_to_push_a(t_stack *b, int median);
void			rotate_to_push_b(t_stack *a, int median);
void			quicksort_a(t_stack *a, t_stack *b, int limit);
void			quicksort_b(t_stack *a, t_stack *b);

void			duo(t_stack *a);

void			trio(t_stack *a);

void			try_rotate(t_stack *a);
void			try_swap(t_stack *a, t_stack *b);
void			rotate_min_to_top(t_stack *a, int min);
void			quint(t_stack *a, t_stack *b);

void			quicksort(t_stack *a, t_stack *b);
int				next_push(t_stack *a, int median);
int				get_median(t_stack *a);
int				get_min(t_stack *a);

void			insertion(t_stack *a, t_stack *b);
int				stack_index(t_stack *a, int n);
int				get_max(t_stack *a);
void			rotate_max_to_top(t_stack *b, int max);

void			place_in_helper(t_stack *a, t_stack *b);
void			place_to_initial_stack(t_stack *a, t_stack *b);
int				is_sort(t_stack *a);
int				is_reverse_sort(t_stack *a);

#endif
