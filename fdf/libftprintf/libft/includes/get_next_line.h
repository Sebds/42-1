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

# include "./libft.h"

typedef struct	s_gnl
{
	char		*read;
	int			last_fd;
	int			init;
}				t_gnl;

# define BUFF_SIZE 1000

int				get_next_line(int fd, char **line);

#endif
