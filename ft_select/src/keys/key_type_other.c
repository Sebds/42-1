/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_type_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:47:21 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 07:07:07 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_bool	key_is_return(char *buff)
{
	static char	*ret = "\x0a\0\0\0\0\0";

	if (ft_memcmp((void *)ret, (void *)buff, MAX_KEY_STRING_LENGTH) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	key_is_space(char *buff)
{
	static char *ret = "\x20\0\0\0\0\0";

	if (ft_memcmp((void *)ret, (void *)buff, MAX_KEY_STRING_LENGTH) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	key_is_escape(char *buff)
{
	static char *ret = "\x1b\0\0\0\0\0";

	if (ft_memcmp((void *)ret, (void *)buff, MAX_KEY_STRING_LENGTH) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	key_is_backspace(char *buff)
{
	static char *ret = "\x7f\0\0\0\0\0";

	if (ft_memcmp((void *)ret, (void *)buff, MAX_KEY_STRING_LENGTH) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	key_is_delete(char *buff)
{
	static char *ret = "\x1b\x5b\x33\x7e\0\0";

	if (ft_memcmp((void *)ret, (void *)buff, MAX_KEY_STRING_LENGTH) == 0)
		return (TRUE);
	return (FALSE);
}
