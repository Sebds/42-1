/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quotestr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:36:48 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:43:41 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

void	ft_trim_quotestr(char *line)
{
	line = ft_memmove(line, line + 1, ft_strlen(line));
	line[ft_strlen(line) - 1] = '\0';
}
