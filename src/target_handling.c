/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:16:50 by bazaluga          #+#    #+#             */
/*   Updated: 2024/04/29 17:33:13 by bazaluga         ###   ########.fr       */
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
	t_frame	*target_a;
	t_frame	*target_b;

	target_a = get_a_target(s->a, f, set);
	target_b = get_a_target(s->b, f, set);
	if (target_a && target_b && target_b->n > f->n && target_b->n < target_a->n)
		target_a = target_b;
	if (set)
		f->target = target_a;
	return (target_a);
}

void	get_all_real_targets(t_stacks *s)
{
	t_frame	*top;

	top = s->a->top;
	while (top)
	{
		get_real_target(s, top, true);
		top = top->next;
	}
	top = s->b->top;
	while (top)
	{
		get_real_target(s, top, true);
		top = top->next;
	}
}
