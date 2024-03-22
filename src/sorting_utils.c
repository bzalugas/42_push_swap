/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:59:29 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/22 13:00:05 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_push(t_stacks *s, t_frame *f)
{
	int	cost;
	int	mid_a;
	int	mid_b;
	int	cost_a;
	int	cost_b;

	mid_a = ((s->a->size + (s->a->size % 2 != 0)) / 2) - 1;
	mid_b = ((s->b->size + (s->b->size % 2 != 0)) / 2) - 1;
	if (f->i <= mid_a)
		cost_a = f->i;
	else
		cost_a = s->a->size - f->i;
	if (!f->target)
		return (cost_a + 1);
	if (f->target->i <= mid_b)
		cost_b = f->target->i;
	else
		cost_b = s->b->size - f->target->i;
	if ((f->i <= mid_a && f->target->i <= mid_b)
		|| (f->i > mid_a && f->target->i > mid_b))
		cost = ft_max_int(cost_a, cost_b);
	else
		cost = ft_max_int(s->a->size - f->i, s->b->size - f->target->i);
	cost = ft_min_int(cost_a + cost_b, cost);
	return (cost + 1);
}

int	frame_sorted(t_stack *s, t_frame *f)
{
	if (!f)
		return (0);
	if (!f->next && !f->prev)
		return (1);
	if (!f->next && f->prev && f->prev->n < f->n)
		return (1);
	if (f->next && !f->prev && f->n < f->next->n)
		return (1);
	if (f->next && f->prev && f->n < f->next->n && f->n > f->prev->n)
		return (1);
	if (f->next && f->n > f->next->n && f == stack_get_max(s)
		&& f->next == stack_get_min(s))
		return (2);
	return (0);
}

void	push_to(t_stacks *s, t_frame *f, bool to_a)
{
	int		mid_a;
	int		mid_b;
	t_frame	*target;

	target = f->target;
	if (to_a)
	{
		target = f;
		f = f->target;
	}
	mid_a = ((s->a->size + (s->a->size % 2 != 0)) / 2) - 1;
	mid_b = ((s->b->size + (s->b->size % 2 != 0)) / 2) - 1;
	while (f->i <= mid_a && f->i > 0)
		ra(s);
	while (f->i > 0)
		rra(s);
	if (target)
	{
		while (target->i <= mid_b && target->i > 0)
			rb(s);
		while (target->i > 0)
		{
			write(1, "here\n", 5);
			rrb(s);
		}
	}
	if (to_a)
		pa(s);
	else
		pb(s);
}

void	push_non_sorted(t_stacks *s)
{
	t_frame	*cheapest;
	int		cost;
	int		min_cost;
	t_frame	*top;

	min_cost = 0;
	cheapest = NULL;
	top = s->a->top;
	while (top && s->a->size > 3)
	{
		if (!frame_sorted(s->a, top))
		{
			get_b_target(s, top);
			cost = cost_push(s, top);
			if (min_cost == 0 || cost < min_cost)
			{
				min_cost = cost;
				cheapest = top;
			}
		}
		top = top->next;
	}
	if (cheapest)
		push_to(s, cheapest, 0);
}

void	get_back_b(t_stacks *s)
{
	t_frame	*cheapest;
	int		cost;
	int		min_cost;
	t_frame	*top;

	while (s->b->size > 0)
	{
		min_cost = 0;
		cheapest = NULL;
		top = s->b->top;
		while (top)
		{
			get_a_target(s, top);
			cost = cost_push(s, top);
			if (min_cost == 0 || cost < min_cost)
			{
				min_cost = cost;
				cheapest = top;
			}
			top = top->next;
		}
		if (cheapest)
			push_to(s, cheapest, 1);
	}
}
