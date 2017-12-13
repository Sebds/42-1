/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:29:20 by nsampre           #+#    #+#             */
/*   Updated: 2017/01/15 21:48:48 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

static char		*ft_strnjoin_free(char *read, char *buf, ssize_t bytes_read)
{
	char	*temp;

	temp = read;
	read = ft_strnjoin(read, buf, bytes_read);
	free(temp);
	return (read);
}

void			ft_gnl_init(t_gnl *gnl, int fd)
{
	if (gnl->init == 0)
	{
		gnl->init = 1;
		gnl->last_fd = -1;
	}
	if (gnl->last_fd != fd)
	{
		gnl->read = ft_strdup("");
		gnl->last_fd = fd;
	}
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	ssize_t			bytes_read;
	static t_gnl	gnl;
	char			*temp;

	if (fd < 0 || !line || read(fd, buf, 0) == -1)
		return (-1);
	ft_gnl_init(&gnl, fd);
	while (!ft_strchr(gnl.read, '\n') && \
		(bytes_read = read(fd, buf, BUFF_SIZE)))
		gnl.read = ft_strnjoin_free(gnl.read, buf, bytes_read);
	bytes_read = 0;
	while (gnl.read[bytes_read] != '\0' && gnl.read[bytes_read] != '\n')
		bytes_read++;
	*line = ft_strsub(gnl.read, 0, bytes_read);
	if ((gnl.read)[bytes_read] == '\n')
		bytes_read++;
	temp = gnl.read;
	gnl.read = ft_strdup(gnl.read + bytes_read);
	free(temp);
	if (bytes_read)
		return (1);
	return (0);
}
