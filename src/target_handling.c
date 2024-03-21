/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:16:50 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/18 14:19:53 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_a_target(t_stacks *s, t_frame *f)
{
	t_frame	*a;
	t_frame	*min;

	f->target = stack_get_max(s->b);
	if (!f->target)
		return ;
	if (f->n > f->target->n)
	{
		f->target = stack_get_min(s->a);
		return ;
	}
	a = s->a->top;
	min = a;
	while (a->next)
	{
		a = a->next;
		if (a->n > f->n && a->n < min->n)
			min = a;
	}
	if (min->n < f->n)
		min = stack_get_min(s->a);
	f->target = min;
}

void	get_b_target(t_stacks *s, t_frame *f)
{
	t_frame	*b;
	t_frame	*max;

	f->target = stack_get_min(s->b);
	if (!f->target)
		return ;
	if (f->n < f->target->n)
	{
		f->target = stack_get_max(s->b);
		return ;
	}
	b = s->b->top;
	max = b;
	while (b->next)
	{
		b = b->next;
		if (b->n < f->n && b->n > max->n)
			max = b;
	}
	if (max->n > f->n)
		max = stack_get_max(s->b);
	f->target = max;
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
