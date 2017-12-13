/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:59:54 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:59:54 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_path(char *path_source)
{
	char	*path_dest;

	if (ft_strequ(path_source, "/"))
	{
		path_dest = ft_strdup("/");
		return (path_dest);
	}
	path_dest = ft_strnew(ft_strlen(path_source) + 1);
	ft_strcpy(path_dest, path_source);
	ft_strcat(path_dest, "/");
	return (path_dest);
}

void	ft_bad_dir(char *path_dir)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(path_dir, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	ft_empty_argv(void)
{
	ft_putstr_fd("ft_ls: fts_open: No such file or directory\n", 2);
	exit(0);
}

int		ft_valid_arg(char *s)
{
	if (s[0] != '-')
		return (1);
	if (s[0] == '-' && ft_strlen(s) == 1)
		return (1);
	return (0);
}

int		ft_no_spec_path(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			return (0);
		else if (argv[i][0] == '-' && ft_strlen(argv[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}
