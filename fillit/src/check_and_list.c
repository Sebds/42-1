/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:07:46 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/22 19:07:46 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	ft_cmp_pack_2(char *input)
{
	if (ft_strcmp(input, "####\n....\n....\n....\n") == 0)
		return (10);
	if (ft_strcmp(input, "#...\n#...\n#...\n#...\n") == 0)
		return (11);
	if (ft_strcmp(input, "##..\n#...\n#...\n....\n") == 0)
		return (12);
	if (ft_strcmp(input, "###.\n..#.\n....\n....\n") == 0)
		return (13);
	if (ft_strcmp(input, ".#..\n.#..\n##..\n....\n") == 0)
		return (14);
	if (ft_strcmp(input, "#...\n###.\n....\n....\n") == 0)
		return (15);
	if (ft_strcmp(input, ".#..\n##..\n.#..\n....\n") == 0)
		return (16);
	if (ft_strcmp(input, ".#..\n###.\n....\n....\n") == 0)
		return (17);
	if (ft_strcmp(input, "#...\n##..\n#...\n....\n") == 0)
		return (18);
	if (ft_strcmp(input, "###.\n.#..\n....\n....\n") == 0)
		return (19);
	return (0);
}

static int	ft_cmp_pack(char *input)
{
	if (ft_strcmp(input, "#...\n##..\n.#..\n....\n") == 0)
		return (1);
	if (ft_strcmp(input, ".#..\n##..\n#...\n....\n") == 0)
		return (2);
	if (ft_strcmp(input, "##..\n##..\n....\n....\n") == 0)
		return (3);
	if (ft_strcmp(input, ".##.\n##..\n....\n....\n") == 0)
		return (4);
	if (ft_strcmp(input, "##..\n.##.\n....\n....\n") == 0)
		return (5);
	if (ft_strcmp(input, "##..\n.#..\n.#..\n....\n") == 0)
		return (6);
	if (ft_strcmp(input, "..#.\n###.\n....\n....\n") == 0)
		return (7);
	if (ft_strcmp(input, "#...\n#...\n##..\n....\n") == 0)
		return (8);
	if (ft_strcmp(input, "###.\n#...\n....\n....\n") == 0)
		return (9);
	return (ft_cmp_pack_2(input));
}

void		ft_check_split_block(char split_block[5][5])
{
	char	block[21];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 20)
	{
		block[i] = split_block[j][k];
		k++;
		i++;
		if (k == 4)
		{
			block[i++] = '\n';
			k = 0;
			j++;
		}
	}
	block[20] = '\0';
	if (FILLIT_DEBUG)
		ft_putendl(block);
	if (ft_cmp_pack(block) == 0)
		ft_quit("Invalid tetromino.");
}

void		ft_shape(t_tetro *all_tetros, char split_block[5][5], int index)
{
	int	i;
	int	j;

	all_tetros->letter = 'A' + index;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (split_block[i][j] == '#')
				all_tetros->shape[i][j] = 1;
			else
				all_tetros->shape[i][j] = 0;
		}
	}
}
