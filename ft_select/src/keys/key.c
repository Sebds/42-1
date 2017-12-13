/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:57:03 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/28 11:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_key	*key_new(t_key_type type, char *value)
{
	t_key	*new;

	new = (t_key *)ft_memalloc(sizeof(t_key));
	new->type = type;
	ft_memcpy((void *)new->value, value, MAX_KEY_STRING_LENGTH);
	return (new);
}

void	key_delete(t_key **akey)
{
	free(*akey);
	*akey = NULL;
}

void	key_init_funcs(t_key_funcs *funcs)
{
	funcs[0].k = KEY_CODE_UP;
	funcs[0].f = key_is_up;
	funcs[1].k = KEY_CODE_DOWN;
	funcs[1].f = key_is_down;
	funcs[2].k = KEY_CODE_LEFT;
	funcs[2].f = key_is_left;
	funcs[3].k = KEY_CODE_RIGHT;
	funcs[3].f = key_is_right;
	funcs[4].k = KEY_CODE_ESCAPE;
	funcs[4].f = key_is_escape;
	funcs[5].k = KEY_CODE_DELETE;
	funcs[5].f = key_is_delete;
	funcs[6].k = KEY_CODE_BKSPACE;
	funcs[6].f = key_is_backspace;
	funcs[7].k = KEY_CODE_SPACE;
	funcs[7].f = key_is_space;
	funcs[8].k = KEY_CODE_RET;
	funcs[8].f = key_is_return;
	funcs[9].k = KEY_CODE_OTHER;
	funcs[9].f = NULL;
}

t_key	*key_get(char *buff)
{
	int			i;
	t_key_funcs *funcs;

	funcs = (t_key_funcs *)ft_memalloc(sizeof(t_key_funcs) * 10);
	key_init_funcs(funcs);
	i = -1;
	while (funcs[++i].f != NULL)
	{
		if (funcs[i].f(buff) == TRUE)
		{
			free(funcs);
			return (key_new(funcs[i].k, buff));
		}
	}
	free(funcs);
	return (key_new(KEY_CODE_OTHER, buff));
}
