/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 13:12:49 by nsampre           #+#    #+#             */
/*   Updated: 2017/05/18 12:07:44 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *input, t_stack *output)
{
	if (input->len == 0)
		return ;
	output->stack[output->len] = input->stack[input->len - 1];
	input->len--;
	output->len++;
}

void	swap(t_stack *input)
{
	int temp;

	if (input->len <= 1)
		return ;
	temp = input->stack[input->len - 1];
	input->stack[input->len - 1] = input->stack[input->len - 2];
	input->stack[input->len - 2] = temp;
}

void	rotate(t_stack *input)
{
	int temp;
	int	i;

	if (input->len == 0)
		return ;
	i = input->len;
	while (--i > 0)
	{
		temp = input->stack[i - 1];
		input->stack[i - 1] = input->stack[i];
		input->stack[i] = temp;
	}
}

void	reverse_rotate(t_stack *input)
{
	int temp;
	int i;

	if (input->len == 0)
		return ;
	i = -1;
	while (++i < input->len - 1)
	{
		temp = input->stack[i];
		input->stack[i] = input->stack[i + 1];
		input->stack[i + 1] = temp;
	}
}
