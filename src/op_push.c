/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:55:37 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/24 17:16:38 by bazaluga         ###   ########.fr       */
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
	if (to->top)
		to->top->prev = from->top;
	to->top = from->top;
	to->size++;
	from->top = tmp;
	if (from->top)
		from->top->prev = NULL;
	from->size--;
	if (from->size == 0)
		from->bot = NULL;
	if (to->size == 1)
		to->bot = to->top;
	stack_update_i(from);
	stack_update_i(to);
	stack_update_mid(from);
	stack_update_mid(to);
}

void	pa(t_stacks *s)
{
	push(s->b, s->a);
	ft_cmdadd_back(&s->cmds, PA);
}

void	pb(t_stacks *s)
{
	push(s->a, s->b);
	ft_cmdadd_back(&s->cmds, PB);
}

void	push_to(t_stacks *s, t_stack *to)
{
	if (to == s->a)
		pa(s);
	else
		pb(s);
}
