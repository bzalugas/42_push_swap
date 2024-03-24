/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:59:29 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/25 00:25:48 by bazaluga         ###   ########.fr       */
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

int	cost_simple_push(t_stack *s, t_frame *f)
{
	int	cost;

	if (f->i <= s->mid)
		cost = f->i;
	else
		cost = s->size - f->i;
	return (cost + 1);
}

int	cost_sort(t_stack *s, t_frame *f)
{
	int	cost1;
	/* int	cost2; */

	cost1 = cost_simple_push(s, f);
	if (f->i <= s->mid)
		cost1 += ft_abs(f->target->i - cost1);
	else
		cost1 += (f->target->i + cost1) % s->size;
	return (cost1 + 1);
	/* cost1++; */
	/* cost2 = cost_simple_push(s, f->target); */
	/* if (f->target->i <= s->mid) */
	/* 	cost2 += ft_abs(f->target->i - cost2); */
	/* else */
	/* 	cost2 += (f->target->i + cost2) % s->size; */
	/* cost2 += 2; */
	/* return (ft_min_int(cost1, cost2)); */
}

void	push_frame(t_stacks *s, t_stack *from, t_stack *to, t_frame *f)
{
	int		mid_f;
	int		mid_t;

	mid_f = ((from->size + (from->size % 2 != 0)) / 2) - 1;
	mid_t = ((to->size + (to->size % 2 != 0)) / 2) - 1;
	while (f->i <= mid_f && f->i > 0)
		rs(s, from);
	while (f->i > 0)
		rrs(s, from);
	if (f->target)
	{
		while (f->target->i <= mid_t && f->target->i > 0)
			rs(s, to);
		while (f->target->i > 0)
			rrs(s, to);
	}
	push_to(s, to);
}

/* bool	sorted(t_stacks *s, t_stack *from, t_frame *f) */
/* { */
/* 	get_real_target(s, f); */
/* 	if (f->next == f->target || (!f->next && f->target == from->top)) */
/* 		return (true); */
/* 	return (false); */
/* } */

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
		/* if ((s->a->size > s->total / 2 && top->n <= s->med) */
		/* 	|| (s->a->size <= s->total / 2 && top->n > s->med)) */
		/* { */
			get_b_target(s->b, top, true);
			cost = cost_push(s->a, s->b, top);
			if (min_cost == 0 || cost < min_cost)
			{
				min_cost = cost;
				cheapest = top;
			}
		/* } */
		top = top->next;
		if (min_cost == 1)
			top = NULL;
	}
	if (cheapest)
	{
		/* ft_printf("cheapest = %d\n", min_cost); */

		push_frame(s, s->a, s->b, cheapest);
	}

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
			get_a_target(s->a, top, true);
			cost = cost_push(s->b, s->a, top);
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
			push_frame(s, s->b, s->a, cheapest);
	}
}
