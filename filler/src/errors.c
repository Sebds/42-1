/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 21:54:37 by nsampre           #+#    #+#             */
/*   Updated: 2017/02/13 21:54:37 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_free_tab(char **tab)
{
	int i;

	if (tab == NULL)
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

int		ft_tab_lines(char **tab)
{
	int i;

	if (!tab || !*tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_check_line(char *line, int len)
{
	if (!line)
		exit(0);
	if ((int)ft_strlen(line) != len)
		exit(0);
}

void	ft_check_tab(char **tab)
{
	int	ret;

	ret = ft_tab_lines(tab);
	if (ret != 3)
		exit(0);
	if (ret == 3 && ft_atoi(tab[1]) < 0)
		exit(0);
	if (ret == 3 && ft_atoi(tab[2]) < 0)
		exit(0);
}
