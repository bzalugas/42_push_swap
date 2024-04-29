/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:59:29 by bazaluga          #+#    #+#             */
/*   Updated: 2024/04/29 16:39:23 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	cost_push(t_stack *from, t_stack *to, t_frame *f)
{
	int	cost;
	int	cost_f;
	int	cost_t;

	if (f->i <= from->mid)
		cost_f = f->i;
	else
		cost_f = from->size - f->i;
	if (!f->target)
		return (cost_f + 1);
	if (f->target->i <= to->mid)
		cost_t = f->target->i;
	else
		cost_t = to->size - f->target->i;
	if ((f->i <= from->mid && f->target->i <= to->mid)
		|| (f->i > from->mid && f->target->i > to->mid))
		cost = ft_max_int(cost_f, cost_t);
	else
		cost = ft_max_int(from->size - f->i, to->size - f->target->i);
	cost = ft_min_int(cost_f + cost_t, cost);
	return (cost + 1);
}

static void	push_frame(t_stacks *s, t_stack *from, t_stack *to, t_frame *f)
{
	while (f->i <= from->mid && f->i > 0)
		rs(s, from);
	while (f->i > 0)
		rrs(s, from);
	if (f->target)
	{
		while (f->target->i <= to->mid && f->target->i > 0)
			rs(s, to);
		while (f->target->i > 0)
			rrs(s, to);
	}
	push_to(s, to);
}

void	push_quartiles(t_stacks *s)
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
		get_b_target(s->b, top, true);
		cost = cost_push(s->a, s->b, top);
		if (min_cost == 0 || cost < min_cost)
		{
			min_cost = cost;
			cheapest = top;
		}
		top = top->next;
		if (min_cost == 1)
			top = NULL;
	}
	if (cheapest)
		push_frame(s, s->a, s->b, cheapest);
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
		get_b_target(s->b, top, true);
		cost = cost_push(s->a, s->b, top);
		if (min_cost == 0 || cost < min_cost)
		{
			min_cost = cost;
			cheapest = top;
		}
		top = top->next;
		if (min_cost == 1)
			top = NULL;
	}
	if (cheapest)
		push_frame(s, s->a, s->b, cheapest);
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
		while (top && min_cost != 1)
		{
			get_a_target(s->a, top, true);
			cost = cost_push(s->b, s->a, top);
			if (min_cost == 0 || cost < min_cost)
			{
				min_cost = cost;
				cheapest = top;
			}
			top = top->next;
		}
		if (cheapest)
			push_frame(s, s->b, s->a, cheapest);
	}
}
