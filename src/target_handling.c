/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:16:50 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/25 00:31:08 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_frame	*get_a_target(t_stack *from, t_frame *f, bool set)
{
	t_frame	*a;
	t_frame	*target;

	if (from->size < 1 && f && set)
		f->target = NULL;
	if (from->size < 1 || !f)
		return (NULL);
	target = stack_get_max(from);
	a = from->top;
	while (a)
	{
		if (a->n > f->n && a->n < target->n)
			target = a;
		a = a->next;
	}
	if (target->n <= f->n)
		target = stack_get_min(from);
	if (set)
	f->target = target;
	return (target);
}

t_frame	*get_b_target(t_stack *from, t_frame *f, bool set)
{
	t_frame	*b;
	t_frame	*target;

	if (from->size < 1 && f && set)
		f->target = NULL;
	if (from->size < 1 || !f)
		return (NULL);
	target = stack_get_min(from);
	b = from->top;
	while (b)
	{
		if (b->n < f->n && b->n > target->n)
			target = b;
		b = b->next;
	}
	if (target->n >= f->n)
		target = stack_get_max(from);
	if (set)
		f->target = target;
	return (target);
}

t_frame	*get_real_target(t_stacks *s, t_frame *f, bool set)
{
	t_frame	*ta;
	t_frame	*tb;
	t_frame	*target;

	if (!f)
		return (NULL);
	tb = get_a_target(s->b, f, false);
	ta = get_a_target(s->a, f, false);
	target = NULL;
	if (!tb)
		target = ta;
	else if (!ta)
		target = tb;
	else if (tb && tb->n > f->n && tb->n < ta->n)
		target = tb;
	else if (tb && f == stack_get_max(s->a) && tb->n < ta->n)
		target = tb;
	if (set)
		f->target = target;
	return (target);
}
