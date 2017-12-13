/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:43:42 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*allocated_mem;

	if ((allocated_mem = malloc(size)) == NULL)
		exit(1);
	ft_bzero(allocated_mem, size);
	return (allocated_mem);
}
