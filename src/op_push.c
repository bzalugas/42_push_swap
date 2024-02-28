/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:55:37 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/28 14:26:39 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_frame	*tmp;

	if (from->size < 1)
		return ;
	tmp = from->top->next;
	from->top->next = to->top;
	to->top = from->top;
	to->size++;
	from->top = tmp;
	from->size--;
	if (from->size == 0)
		from->bot = NULL;
	if (to->size == 1)
		to->bot = to->top;
	stack_update_i(from);
	stack_update_i(to);
}

void	pa(t_stacks *stacks)
{
	push(stacks->b, stacks->a);
}

void	pb(t_stacks *stacks)
{
	push(stacks->a, stacks->b);
}
