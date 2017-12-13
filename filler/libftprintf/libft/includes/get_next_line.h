/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:29:31 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/10 15:45:57 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024

# include "libft.h"

typedef struct		s_gnl
{
	int				fd;
	char			*buf_line;
	char			*buf_pos;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
