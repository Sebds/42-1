/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 22:31:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 23:20:47 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		test_spaces(char *str, int *i)
{
	int space;

	*i = -1;
	space = 0;
	while (str[++(*i)])
		if (str[*i] == ' ')
			space++;
	*i = 0;
	if (space != 2 || str[0] == ' ' || str[ft_strlen(str) - 1] == ' ')
		return (0);
	return (1);
}

int		ft_room_pattern(char *str)
{
	int		i;
	char	*ptr;
	char	*test;

	if ((str && str[0] == '#') || !test_spaces(str, &i))
		return (0);
	ptr = ft_strchr(str, ' ') + 1;
	test = str - 1;
	while (++test != ptr)
	{
		if (*test == '-')
			ft_quit("Illegal '-' symbol in room name");
	}
	if (ptr[i] == '-')
		i++;
	while (ft_isdigit(ptr[i]))
		i++;
	if (ptr[i] != ' ')
		return (0);
	i++;
	if (ptr[i] == '-')
		i++;
	while (ft_isdigit(ptr[i]))
		i++;
	return (ptr[i] == '\0');
}

int		ft_comment_pattern(char *str)
{
	if (!str || !*str)
		return (0);
	if (ft_strequ(str, "##start"))
		return (2);
	if (ft_strequ(str, "##end"))
		return (3);
	if (ft_strstr(str, "##"))
		return (4);
	if (str[0] == '#')
		return (5);
	if (str[0] == 'L')
		return (1);
	return (0);
}

int		ft_pipe_pattern(char *str)
{
	int dash;
	int	space;
	int i;

	if (str && str[0] == '#')
		return (0);
	dash = 0;
	space = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			dash++;
		if (str[i] == ' ')
			space++;
		i++;
	}
	if (space || dash != 1 || str[0] == '-' || str[ft_strlen(str) - 1] == '-')
		return (0);
	return (1);
}
