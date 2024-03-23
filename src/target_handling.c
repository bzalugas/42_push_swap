/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:16:50 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/23 18:18:15 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_a_target(t_stack *from, t_frame *f)
{
	t_frame	*a;

	if (from->size < 1)
	{
		f->target = NULL;
		return ;
	}
	f->target = stack_get_max(from);
	if (f->n > f->target->n)
	{
		f->target = stack_get_min(from);
		return ;
	}
	a = from->top;
	while (a)
	{
		if (a->n > f->n && a->n < f->target->n)
			f->target = a;
		a = a->next;
	}
	if (f->target->n <= f->n)
		f->target = stack_get_min(from);
}

void	get_b_target(t_stack *from, t_frame *f)
{
	t_frame	*b;

	if (from->size < 1)
	{
		f->target = NULL;
		return ;
	}
	f->target = stack_get_min(from);
	if (f->n < f->target->n)
	{
		f->target = stack_get_max(from);
		return ;
	}
	b = from->top;
	while (b)
	{
		if (b->n < f->n && b->n > f->target->n)
			f->target = b;
		b = b->next;
	}
	if (f->target->n >= f->n)
		f->target = stack_get_max(from);
}

void	get_real_target(t_stacks *s, t_frame *f)
{
	t_frame	*ta;
	t_frame	*tb;

	get_a_target(s->b, f);
	tb = f->target;
	get_a_target(s->a, f);
	ta = f->target;
	if (!ta)
		f->target = tb;
	else if (tb && tb->n > f->n && tb->n < ta->n)
		f->target = tb;
	else if (tb && f == stack_get_max(s->a) && tb->n < ta->n)
		f->target = tb;
}
