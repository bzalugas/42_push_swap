/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:59:29 by bazaluga          #+#    #+#             */
/*   Updated: 2024/05/06 23:07:20 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_push(t_stack *from, t_stack *to, t_frame *f, bool use_target)
{
	int	costs[4];
	int	cost;

	f->next_ops[0] = R;
	f->next_ops[1] = 0;
	if (!f->target || use_target == false)
	{
		cost = ft_min(f->i, from->size - f->i);
		if (cost != f->i)
			f->next_ops[0] = RRO;
		return (cost + 1);
	}
	costs[0] = ft_max(f->i, f->target->i);
	costs[1] = ft_max(from->size - f->i, to->size - f->target->i);
	costs[2] = f->i + (to->size - f->target->i);
	costs[3] = (from->size - f->i) + f->target->i;
	cost = *ft_min_arr(costs, 4);
	if (cost == costs[1] || cost == costs[3])
		f->next_ops[0] = RRO;
	if (cost == costs[0] || cost == costs[3])
		f->next_ops[1] = R;
	else
		f->next_ops[1] = RRO;
	return (cost + 1);
}

void	push_frame(t_stacks *s, t_stack *from, t_stack *to, t_frame *f)
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

void	push_non_sorted(t_stacks *s)
{
	t_frame	*cheapest;
	int		cost;
	int		min_cost;
	t_frame	*top;

	min_cost = 0;
	cheapest = NULL;
	top = s->a->top;
	while (top && s->a->size > 3 && min_cost != 1)
	{
		get_b_target(s->b, top, true);
		cost = cost_push(s->a, s->b, top, true);
		if (min_cost == 0 || cost < min_cost)
		{
			min_cost = cost;
			cheapest = top;
		}
		top = top->next;
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
