/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_type_arrow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:44:44 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 06:53:55 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_bool	key_is_up(char *buff)
{
	static char *arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("ku", NULL);
		if (!arrow)
			return (FALSE);
		arrow[1] = 91;
	}
	if (ft_memcmp((void *)arrow, (void *)buff, ft_strlen(arrow)) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	key_is_down(char *buff)
{
	static char *arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kd", NULL);
		if (!arrow)
			return (FALSE);
		arrow[1] = 91;
	}
	if (ft_memcmp((void *)arrow, (void *)buff, ft_strlen(arrow)) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	key_is_left(char *buff)
{
	static char *arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kl", NULL);
		if (!arrow)
			return (FALSE);
		arrow[1] = 91;
	}
	if (ft_memcmp((void *)arrow, (void *)buff, ft_strlen(arrow)) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	key_is_right(char *buff)
{
	static char *arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kr", NULL);
		if (!arrow)
			return (FALSE);
		arrow[1] = 91;
	}
	if (ft_memcmp((void *)arrow, (void *)buff, ft_strlen(arrow)) == 0)
		return (TRUE);
	return (FALSE);
}
