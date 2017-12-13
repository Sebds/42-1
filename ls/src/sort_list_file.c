/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:18:59 by nsampre           #+#    #+#             */
/*   Updated: 2016/12/23 03:18:59 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*ft_sort_file_time(t_file *a, t_file *b)
{
	t_file	*sorted;

	sorted = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->date >= b->date)
	{
		sorted = a;
		sorted->next = ft_sort_file_time(a->next, b);
	}
	else
	{
		sorted = b;
		sorted->next = ft_sort_file_time(a, b->next);
	}
	return (sorted);
}

t_file	*ft_sort_file_name(t_file *a, t_file *b)
{
	t_file	*sorted;

	sorted = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->name, b->name) < 0)
	{
		sorted = a;
		sorted->next = ft_sort_file_name(a->next, b);
	}
	else
	{
		sorted = b;
		sorted->next = ft_sort_file_name(a, b->next);
	}
	return (sorted);
}

void	ft_split_file(t_file *source, t_file **front, t_file **back)
{
	t_file	*before;
	t_file	*after;

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

void	ft_sort_file(t_file **begin, char c)
{
	t_file	*head;
	t_file	*a;
	t_file	*b;

	head = *begin;
	if (head == NULL || head->next == NULL)
		return ;
	ft_split_file(head, &a, &b);
	ft_sort_file(&a, c);
	ft_sort_file(&b, c);
	if (c == 't')
		*begin = ft_sort_file_time(a, b);
	if (c == 'n')
		*begin = ft_sort_file_name(a, b);
}

void	ft_file_reverse(t_file **list)
{
	t_file	*prev;
	t_file	*current;
	t_file	*next;

	prev = NULL;
	if (!list)
		return ;
	if (*list)
	{
		current = *list;
		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*list = prev;
	}
}
