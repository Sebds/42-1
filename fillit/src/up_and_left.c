/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_and_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:56:01 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/23 10:02:45 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_split_b	ft_split_block(char *input)
{
	int			i;
	int			j;
	int			k;
	t_split_b	split_block;

	i = 0;
	j = 0;
	k = 0;
	while (input[k] != '\0')
	{
		split_block.b[i][j] = input[k];
		j++;
		if (j == 4)
		{
			split_block.b[i][j] = '\0';
			j = 0;
			i++;
			k++;
		}
		k++;
	}
	ft_strcpy(split_block.b[i], "");
	return (split_block);
}

static void	ft_swap_columns(char split_input[5][5], int i)
{
	char	temp;
	int		j;

	j = -1;
	while (++j < 4)
	{
		temp = split_input[j][i];
		split_input[j][i] = split_input[j][i + 1];
		split_input[j][i + 1] = temp;
	}
}

void		ft_place_up(char split_input[5][5])
{
	char	temp[5];
	int		i;
	int		j;

	i = 0;
	while (split_input[i++] && ft_strcmp(split_input[0], "....") == 0)
	{
		j = -1;
		while (++j < 3)
		{
			if (ft_strcmp(split_input[j], "....") == 0)
			{
				ft_strcpy(temp, split_input[j]);
				ft_strcpy(split_input[j], split_input[j + 1]);
				ft_strcpy(split_input[j + 1], temp);
			}
		}
	}
}

void		ft_place_left(char split_input[5][5])
{
	char	column[5];
	int		i;

	column[0] = split_input[0][0];
	column[1] = split_input[1][0];
	column[2] = split_input[2][0];
	column[3] = split_input[3][0];
	column[4] = '\0';
	while (ft_strcmp(column, "....") == 0)
	{
		i = -1;
		while (++i < 3)
		{
			ft_swap_columns(split_input, i);
		}
		column[0] = split_input[0][0];
		column[1] = split_input[1][0];
		column[2] = split_input[2][0];
		column[3] = split_input[3][0];
		column[4] = '\0';
	}
}

t_tetro		*ft_place_up_and_left(t_split split_input)
{
	int					i;
	t_split_b			split_block;
	static t_tetro		all_tetros[27];

	i = 0;
	while (ft_strcmp(split_input.array[i], "") != 0)
	{
		split_block = ft_split_block(split_input.array[i]);
		ft_place_up(split_block.b);
		ft_place_left(split_block.b);
		ft_check_split_block(split_block.b);
		ft_shape(&all_tetros[i], split_block.b, i);
		all_tetros[i].next = &all_tetros[i + 1];
		i++;
	}
	return (all_tetros);
}
