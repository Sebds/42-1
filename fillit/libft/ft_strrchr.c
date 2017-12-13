/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:43 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/06 16:37:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = ft_strlen((char *)s) + 1;
	while (--count)
	{
		if (s[count] == (char)c)
			return ((char *)s + count);
	}
	if (s[count] == (char)c)
		return ((char *)s + count);
	return (NULL);
}
