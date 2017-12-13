/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:00:39 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/22 19:00:39 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_check_split_input(char input[26][21])
{
	int	i;
	int j;
	int count_hashtag;

	i = -1;
	while (ft_strcmp(input[++i], "") != 0)
	{
		if (ft_strlen(input[i]) != 20)
			ft_quit("Not even a block");
		count_hashtag = 0;
		j = -1;
		while (input[i][++j])
		{
			if (input[i][j] == '#')
				++count_hashtag;
		}
		if (count_hashtag != 4)
			ft_quit("# in block.");
	}
}

t_split		ft_split_input(char *full_fd)
{
	int		i;
	int		j;
	int		k;
	t_split	split_input;

	i = 0;
	j = 0;
	k = 0;
	while (full_fd[k] != '\0')
	{
		ft_strcpy(split_input.array[i + 1], "");
		split_input.array[i][j] = full_fd[k];
		j++;
		if (j == 20)
		{
			split_input.array[i][j] = '\0';
			j = 0;
			i++;
			k++;
		}
		k++;
	}
	ft_check_split_input(split_input.array);
	return (split_input);
}

static void	ft_check_newline(char *full_fd)
{
	size_t	len;

	len = ft_strlen(full_fd);
	if (len < 20)
		ft_quit("Input is not even the size of a regular block.");
	if (full_fd[0] == '\n')
		ft_quit("Some mewline at the begining.");
	if (full_fd[len - 1] == '\n' && full_fd[len - 2] == '\n')
		ft_quit("Too many newlines at the end.");
}

char		*ft_read_input(int fd)
{
	static char		full_fd[545 + 1];
	char			buf[545 + 1];
	ssize_t			bytes_read;

	bytes_read = read(fd, &buf, 545 + 1);
	if (bytes_read == -1)
		ft_quit("Unvalid input file.");
	if (bytes_read > 545)
		ft_quit("Too big input.");
	else
		buf[bytes_read] = '\0';
	ft_strcpy(full_fd, buf);
	ft_check_newline(full_fd);
	return (full_fd);
}
