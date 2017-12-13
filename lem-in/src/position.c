/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:22:44 by nsampre           #+#    #+#             */
/*   Updated: 2017/03/16 22:57:16 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_pos	*ft_new_pos(void)
{
	t_pos *new;

	if (!(new = (t_pos *)malloc(sizeof(t_pos))))
		ft_quit("Failed to alloc pos structure.");
	new->next = NULL;
	return (new);
}

void	ft_pos_push_back(t_pos **list, t_pos *cur)
{
	if (!list)
		return ;
	while (*list)
		list = &(*list)->next;
	*list = cur;
}

t_pos	*ft_create_pos(t_ant *ant)
{
	int		i;
	t_pos	*head;
	t_pos	*cur;

	i = -1;
	head = NULL;
	while (++i < ant->ant_number)
	{
		cur = ft_new_pos();
		cur->num = i + 1;
		cur->current_room = ant->start_index;
		ft_pos_push_back(&head, cur);
	}
	return (head);
}
