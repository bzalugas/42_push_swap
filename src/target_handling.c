/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:16:50 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/25 01:21:49 by bazaluga         ###   ########.fr       */
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
