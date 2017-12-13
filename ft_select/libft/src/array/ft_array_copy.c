/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:36:47 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:43:41 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_copy(char **s)
{
	int		i;
	char	**array;

	array = (char **)ft_memalloc(sizeof(char *) * (ft_array_len(s) + 2));
	i = 0;
	while (s && s[i])
	{
		array[i] = ft_strdup(s[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}
