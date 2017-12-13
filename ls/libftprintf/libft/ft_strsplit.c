/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:42 by nsampre           #+#    #+#             */
/*   Updated: 2016/11/08 23:50:00 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		ft_count_words(char *s, char splitter)
{
	int count_word;
	int in_word;
	int i;

	in_word = 0;
	count_word = 0;
	i = 0;
	while (s[i])
	{
		if (in_word == 1 && s[i] == splitter)
			in_word = 0;
		if (in_word == 0 && s[i] != splitter)
		{
			in_word = 1;
			count_word++;
		}
		i++;
	}
	return (count_word);
}

static char		*new_and_sub(int i, int start, char *s)
{
	char *tab;

	tab = ft_strsub(s, start, i - start);
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		start;
	int		count_word;

	if (s == NULL)
		return (NULL);
	count_word = ft_count_words((char *)s, c);
	if (!(tab = malloc((sizeof(char *) * (count_word + 1)))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < count_word && tab)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = new_and_sub(i, start, (char *)s);
		i++;
	}
	(tab) ? (tab[j] = 0) : (0);
	return (tab);
}
