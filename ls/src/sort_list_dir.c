/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:18:44 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:18:44 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir	*ft_sort_dir_time(t_dir *a, t_dir *b)
{
	t_dir	*sorted;

	sorted = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->date >= b->date)
	{
		sorted = a;
		sorted->next = ft_sort_dir_time(a->next, b);
	}
	else
	{
		sorted = b;
		sorted->next = ft_sort_dir_time(a, b->next);
	}
	return (sorted);
}

t_dir	*ft_sort_dir_path(t_dir *a, t_dir *b)
{
	t_dir	*sorted;

	sorted = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->path_dir, b->path_dir) < 0)
	{
		sorted = a;
		sorted->next = ft_sort_dir_path(a->next, b);
	}
	else
	{
		sorted = b;
		sorted->next = ft_sort_dir_path(a, b->next);
	}
	return (sorted);
}

void	ft_split_dir(t_dir *source, t_dir **front, t_dir **back)
{
	t_dir	*before;
	t_dir	*after;

	if (source == NULL || source->next == NULL)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		after = source;
		before = source->next;
		while (before != NULL)
		{
			before = before->next;
			if (before != NULL)
			{
				after = after->next;
				before = before->next;
			}
		}
		*front = source;
		*back = after->next;
		after->next = NULL;
	}
}

void	ft_sort_dir(t_dir **begin, char c)
{
	t_dir	*head;
	t_dir	*a;
	t_dir	*b;

	head = *begin;
	if (head == NULL || head->next == NULL)
		return ;
	ft_split_dir(head, &a, &b);
	ft_sort_dir(&a, c);
	ft_sort_dir(&b, c);
	if (c == 't')
		*begin = ft_sort_dir_time(a, b);
	if (c == 'n')
		*begin = ft_sort_dir_path(a, b);
}

void	ft_dir_reverse(t_dir **dir)
{
	t_dir	*prev;
	t_dir	*current;
	t_dir	*next;

	prev = NULL;
	if (!dir)
		return ;
	if (*dir)
	{
		current = *dir;
		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*dir = prev;
	}
}
