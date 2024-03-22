/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:16:50 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/22 14:45:18 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_a_target(t_stacks *s, t_frame *f)
{
	t_frame	*a;

	if (s->a->size < 1)
		return ;
	f->target = stack_get_max(s->a);
	if (f->n > f->target->n)
	{
		f->target = stack_get_min(s->a);
		return ;
	}
	a = s->a->top;
	while (a)
	{
		if (a->n > f->n && a->n < f->target->n)
			f->target = a;
		a = a->next;
	}
	if (f->target->n < f->n)
		f->target = stack_get_min(s->a);
}

void	get_b_target(t_stacks *s, t_frame *f)
{
	t_frame	*b;

	if (s->b->size < 1)
		return ;
	f->target = stack_get_min(s->b);
	if (f->n < f->target->n)
	{
		f->target = stack_get_max(s->b);
		return ;
	}
	b = s->b->top;
	while (b)
	{
		if (b->n < f->n && b->n > f->target->n)
			f->target = b;
		b = b->next;
	}
	if (f->target->n > f->n)
		f->target = stack_get_max(s->b);
}

void	get_all_b_targets(t_stacks *s)
{
	t_frame	*top;

	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		top = top->next;
	}
}
