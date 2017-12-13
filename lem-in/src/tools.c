/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 22:31:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_quit(char *reason)
{
	ft_putstr_fd("Error\n", 1);
	if (LEM_IN_DEBUG)
	{
		ft_putstr("\x1b[31m");
		ft_putendl_fd(reason, 2);
		ft_putstr("\x1b[0m");
	}
	sleep(LEAKS_TIME);
	exit(EXIT_FAILURE);
}

int		ft_is_number(char *str)
{
	int i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	ft_free_tab(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
