/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:59:29 by bazaluga          #+#    #+#             */
/*   Updated: 2024/05/03 06:06:54 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* int	cost_push(t_stack *from, t_stack *to, t_frame *f, bool use_target) */
/* { */
/* 	int	costs[4]; */
/* 	int	cost; */

/* 	if (!f->target || !use_target) */
/* 	{ */
/* 		cost = ft_min_int(f->i, from->size - f->i); */
/* 		if (cost == f->i) */
/* 			f->op = R; */
/* 		else */
/* 			f->op = RRO; */
/* 		return (cost + 1); */
/* 	} */
/* 	costs[0] = ft_max_int(f->i, f->target->i); */
/* 	costs[1] = ft_max_int(from->size - f->i, to->size - f->target->i); */
/* 	costs[2] = f->i + (to->size - f->target->i); */
/* 	costs[3] = (from->size - f->i) + f->target->i; */
/* 	cost = ft_min_int(ft_min_int(costs[0], costs[1]), */
/* 					  ft_min_int(costs[2], costs[3])); */
/* 	f->op = RRO; */
/* 	if (cost == costs[0] || cost == costs[2]) */
/* 		f->op = R; */
/* 	f->target->op = RRO; */
/* 	if (cost == costs[0] || cost == costs[3]) */
/* 		f->target->op = R; */
/* 	return (cost + 1); */
/* } */

/* void	push_frame(t_stacks *s, t_stack *from, t_stack *to, t_frame *f) */
/* { */
/* 	int	count_r1; */
/* 	int	count_rr1; */
/* 	int	count_r2; */
/* 	int	count_rr2; */
/* 	static int call = 0; */

/* 	count_r1 = 0; */
/* 	count_rr1 = 0; */
/* 	count_r2 = 0; */
/* 	count_rr2 = 0; */
/* 	call++; */
/* 	/\* if (f->op == R && f->i > from->mid) *\/ */
/* 	/\* 	ft_printf("Rotate instead of RevRotate at call %d\n", call); *\/ */
/* 	/\* if (f->op == RRO && f->i <= from->mid) *\/ */
/* 	/\* 	ft_printf("RevRotate instead of Rotate at call %d\n", call); *\/ */
/* 	/\* if (f->target && f->target->op == R && f->target->i > to->mid) *\/ */
/* 	/\* 	ft_printf("Rotate instead of RevRotate at call %d\n", call); *\/ */
/* 	/\* if (f->target && f->target->op == RRO && f->target->i <= to->mid) *\/ */
/* 	/\* 	ft_printf("RevRotate instead of Rotate at call %d\n", call); *\/ */
/* 	while (f->op == R && f->i > 0) */
/* 	{ */
/* 		count_r1++; */
/* 		rs(s, from); */
/* 	} */

/* 	while (f->op == RRO && f->i > 0) */
/* {		count_rr1++; */
/* 		rrs(s, from);} */
/* 	if (f->target) */
/* 	{ */
/* 		while (f->target->op == R && f->target->i > 0) */
/* 		{ */
/* 			count_r2++; */
/* 			rs(s, to); */
/* 		} */
/* 		while (f->target->op == RRO && f->target->i > 0) */
/* 			{count_rr2++; */
/* 			rrs(s, to);} */
/* 	} */
/* 	/\* int real = ft_max_int(ft_max_int(ft_max_int(count_r1, count_r2), ft_max_int(count_rr1, count_rr2)), ft_max_int(count_r1 + count_rr2, count_rr1 + count_r2)); *\/ */
/* 	/\* ft_printf("real cost = %d\n\n", real + 1); *\/ */
/* 	push_to(s, to); */
/* } */


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
		cost = ft_max_int(cost_f, cost_t);
	else
		cost = ft_min_int(ft_max_int(from->size - f->i, to->size - f->target->i),
			ft_max_int(f->i, f->target->i));
	cost = ft_min_int(cost_f + cost_t, cost);
	return (cost + 1);
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
	t_frame	*top;

	min_cost = 0;
	cheapest = NULL;
	top = s->a->top;
	while (top && s->a->size > 3 && (cost == 0 || cost > 1))
	{
		get_b_target(s->b, top, true);
		cost = cost_push(s->a, s->b, top, true);
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
	{
		/* ft_printf("min_cost = %d\n", min_cost); */
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
		while (top && min_cost != 1)
		{
			get_a_target(s->a, top, true);
			cost = cost_push(s->b, s->a, top, true);
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
