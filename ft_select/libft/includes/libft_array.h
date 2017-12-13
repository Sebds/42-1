/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:36:48 by nsampre           #+#    #+#             */
/*   Updated: 2017/06/10 20:43:41 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAY_H
# define LIBFT_ARRAY_H

# include "libft.h"

char	**ft_array_copy(char **s);
int		ft_array_len(char **array);
int		ft_free_array(char **array);
void	ft_print_array(char **array);
char	**ft_post_realloc_array(char **array, char *line);
char	**ft_pre_realloc_array(char **array, char *line);

#endif
