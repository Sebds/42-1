/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:42 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/06 16:37:42 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (s == NULL)
		return (NULL);
	if (!(new_s = ft_strnew(len)))
		return (NULL);
	ft_strncpy(new_s, (char *)s + start, (int)len);
	if (new_s)
		new_s[len + 1] = '\0';
	return (new_s);
}
