/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:59:29 by bazaluga          #+#    #+#             */
/*   Updated: 2024/05/06 22:38:07 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_push(t_stack *from, t_stack *to, t_frame *f, bool use_target)
{
	int	cost;
	int	cost_f;
	int	cost_t;

	if (f->i <= from->mid)
		cost_f = f->i;
	else
		cost_f = from->size - f->i;
	if (!f->target || use_target == false)
		return (cost_f + 1);
	if (f->target->i <= to->mid)
		cost_t = f->target->i;
	else
		cost_t = to->size - f->target->i;
	if ((f->i <= from->mid && f->target->i <= to->mid)
		|| (f->i > from->mid && f->target->i > to->mid))
		cost = ft_max(cost_f, cost_t);
	else
		cost = ft_max(from->size - f->i, to->size - f->target->i); //????
	cost = ft_min(cost_f + cost_t, cost);
	return (cost + 1);
}

int		cost2(t_stack *from, t_stack *to, t_frame *f, bool use_target)
{
	int	costs[4];
	int	cost;

	if (!f->target || use_target == false)
	{
		f->next_ops[1] = 0;
		cost = ft_min(f->i, from->size - f->i);
		if (cost == f->i)
			f->next_ops[0] = R;
		else
			f->next_ops[0] = RR;
		return (cost + 1);
	}
	costs[0] = ft_max(f->i, f->target->i);
	costs[1] = ft_max(from->size - f->i, to->size - f->target->i);
	costs[2] = f->i + (to->size - f->target->i);
	costs[3] = (from->size - f->i) + f->target->i;
	cost = *ft_min_arr(costs, 4);
	if (cost == costs[0] || cost == costs[2])
		f->next_ops[0] = R;
	else
		f->next_ops[0] = RRO;
	if (cost == costs[0] || cost == costs[3])
		f->next_ops[1] = R;
	else
		f->next_ops[1] = RRO;
	return (cost + 1);
}

void	push_2(t_stacks *s, t_stack *from, t_stack *to, t_frame *f)
{
	while (f->next_ops[0] == R && f->i > 0)
		rs(s, from);
	while (f->next_ops[0] == RRO && f->i > 0)
		rrs(s, from);
	if (f->target)
	{
		while (f->next_ops[1] == R && f->target->i > 0)
			rs(s, to);
		while (f->next_ops[1] == RRO && f->target->i > 0)
			rrs(s, to);
	}
	push_to(s, to);
}

void	push_frame(t_stacks *s, t_stack *from, t_stack *to, t_frame *f)
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

void	push_non_sorted(t_stacks *s)
{
	t_frame	*cheapest;
	int		cost;
	int		min_cost;
	/* t_frame	*cheapest1; */
	/* int		cost1; */
	/* int		min_cost1; */
	t_frame	*top;
	int real;
	/* static int n = 0; */

	/* n++; */
	min_cost = 0;
	cheapest = NULL;
	top = s->a->top;
	/* while (top && s->a->size > 3 && (min_cost == 0 || min_cost > 1)) */
	while (top && s->a->size > 3)
	{
		get_b_target(s->b, top, true);
		cost = cost_push(s->a, s->b, top, true);
		/* cost1 = cost2(s->a, s->b, top, true); */
		if (min_cost == 0 || cost < min_cost)
		{
			min_cost = cost;
			cheapest = top;
		}
		/* if (min_cost1 == 0 || cost1 < min_cost1) */
		/* { */
		/* 	min_cost1 = cost1; */
		/* 	cheapest1 = top; */
		/* } */
		top = top->next;
		/* if (min_cost1 == 1) */
		/* 	top = NULL; */
	}
	/* if (cheapest1) */
	/* { */
	/* 	real = push_2(s, s->a, s->b, cheapest1); */
	/* 	if (real != min_cost1) */
	/* 		ft_printf("(push n.%d) DIFF for %d: min_cost = %d, real = %d\n\n", n, cheapest1->n, min_cost1, real); */
	/* } */

	if (cheapest)
		push_frame(s, s->a, s->b, cheapest);
}

void	get_back_b(t_stacks *s)
{
	t_frame	*cheapest;
	int		cost;
	int		min_cost;
	/* t_frame	*cheapest1; */
	/* int		cost1; */
	/* int		min_cost1; */
	t_frame	*top;

	while (s->b->size > 0)
	{
		min_cost = 0;
		cheapest = NULL;
		top = s->b->top;
		while (top && min_cost != 1)
		{
			get_a_target(s->a, top, true);
			cost = cost_push(s->b, s->a, top, true);
			/* cost1 = cost2(s->b, s->a, top, true); */
			if (min_cost == 0 || cost < min_cost)
			{
				min_cost = cost;
				cheapest = top;
			}
			/* if (min_cost1 == 0 || cost1 < min_cost1) */
			/* { */
			/* 	min_cost1 = cost1; */
			/* 	cheapest1 = top; */
			/* } */
			top = top->next;
		}
		if (cheapest)
			push_frame(s, s->b, s->a, cheapest);
		/* if (cheapest1) */
		/* 	push_2(s, s->b, s->a, cheapest); */
	}
}
