/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_realloc_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:36:47 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:43:41 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_pre_realloc_array(char **array, char *new_line)
{
	char	**new_array;
	int		i;
	int		len;

	len = (sizeof(char *) * (ft_array_len(array) + 2));
	new_array = (char **)ft_memalloc(len);
	new_array[0] = ft_strdup(new_line);
	i = 1;
	while (array && array[i - 1])
	{
		new_array[i] = ft_strdup(array[i - 1]);
		i++;
	}
	new_array[i] = NULL;
	ft_free_array(array);
	return (new_array);
}
