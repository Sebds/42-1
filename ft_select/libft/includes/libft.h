/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:58:15 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:54:30 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# include "libftprintf.h"
# include "libft_array.h"
# include "libft_char.h"
# include "libft_convertion.h"
# include "libft_lst.h"
# include "libft_math.h"
# include "libft_mem.h"
# include "libft_put.h"
# include "libft_string.h"

# define BUFF_SIZE 1024

typedef struct	s_gnl
{
	int				fd;
	char			*buf_line;
	char			*buf_pos;
}				t_gnl;

int				get_next_line(const int fd, char **line);

typedef struct	s_strrepace
{
	int				len_rep;
	int				len_with;
	int				len_front;
	int				count;
}				t_strreplace;

#endif
