/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:59:54 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_allow_recursive(char *dir_to_open)
{
	if (ft_strequ(dir_to_open, ".."))
		return (0);
	if (ft_strequ(dir_to_open, "."))
		return (0);
	if (ft_strlen(dir_to_open) == 0)
		return (0);
	return (1);
}

int		ft_intlen(unsigned long long n)
{
	int i;

	i = 1;
	while ((n /= 10) > 0)
		i++;
	return (i);
}

int		ft_minor(int m)
{
	return ((int32_t)(((u_int32_t)(m) >> 24) & 0xff));
}

int		ft_major(int m)
{
	return ((int32_t)((m) & 0xffffff));
}

void	ft_usage(char c, char d)
{
	if (c != 'a' &&
		c != 'l' &&
		c != 'r' &&
		c != 't' &&
		c != 'R' &&
		c != '1')
	{
		if (c == '-' && !d)
			return ;
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("\nusage: ft_ls [-R1alrt] [file ...]\n", 2);
		exit(1);
	}
}
