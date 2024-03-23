/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:59:29 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/23 15:27:45 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_push(t_stack *from, t_stack *to, t_frame *f)
{
	int	cost;
	int	mid_f;
	int	mid_t;
	int	cost_f;
	int	cost_t;

	mid_f = ((from->size + (from->size % 2 != 0)) / 2) - 1;
	mid_t = ((to->size + (to->size % 2 != 0)) / 2) - 1;
	if (f->i <= mid_f)
		cost_f = f->i;
	else
		cost_f = from->size - f->i;
	if (!f->target)
		return (cost_f + 1);
	if (f->target->i <= mid_t)
		cost_t = f->target->i;
	else
		cost_t = to->size - f->target->i;
	if ((f->i <= mid_f && f->target->i <= mid_t)
		|| (f->i > mid_f && f->target->i > mid_t))
		cost = ft_max_int(cost_f, cost_t);
	else
		cost = ft_max_int(from->size - f->i, to->size - f->target->i);
	cost = ft_min_int(cost_f + cost_t, cost);
	return (cost + 1);
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
			rrb(s);
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
		get_b_target(s, top);
		cost = cost_push(s->a, s->b, top);
		if (min_cost == 0 || cost < min_cost)
		{
			min_cost = cost;
			cheapest = top;
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
			cost = cost_push(s->b, s->a, top);
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
