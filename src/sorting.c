/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/25 00:37:53 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stacks *s)
{
	t_stack	*a;

	a = s->a;
	if (a->size != 3)
		return ;
	if (a->top == stack_get_max(a))
		sa(s);
	if (a->top->next->n > a->bot->n)
		rra(s);
	if (a->top->n > a->top->next->n)
		sa(s);
}

void	order_stack(t_stacks *s)
{
	t_frame	*min;
	int		mid_a;//use s->a->mid

	mid_a = ((s->a->size + (s->a->size % 2 != 0)) / 2) - 1;
	min = stack_get_min(s->a);
	while (min->i <= mid_a && min->i > 0)
		ra(s);
	while (min->i > mid_a && min->i > 0)
		rra(s);
}

void	sort_frame(t_stacks *s, t_frame *f)
{
	if (f->target == get_b_target(s->b, f, false))
	{
		push_frame(s, s->a, s->b, f);
		return ;
	}
	if (f == stack_get_max(s->a))
		return ;
	while (f->i <= s->a->mid && f->i > 0)
		ra(s);
	while (f->i > s->a->mid && f->i > 0)
		rra(s);

	/* get_a_target(s->a, f); */
	/* get_a_target(s->a, f->next); */
	/* if (f->next->target == f) */
	/* 	sa(s); */
	/* else */
	/* { */
		pb(s);
		push_frame(s, s->b, s->a, f);
	/* } */
}

void	sort_stack(t_stacks *ss, t_stack *s)
{
	t_frame	*top;
	int		min_cost;
	int		cost;
	t_frame	*cheapest;
	t_frame	*target;
	int score;
	while (stack_score(s) != s->size)
	{
		score = stack_score(s);
		(void)score;
		min_cost = 0;
		cheapest = NULL;
		top = s->top;
		while (top)
		{
			target = get_a_target(s, top, false);
			get_real_target(ss, top, true);
			if (top->next != top->target)
			{
				if (target != top->target)
					cost = cost_push(ss->a, ss->b, top);
				else
					cost = cost_sort(s, top);
				if (min_cost == 0 || cost < min_cost)
				{
					min_cost = cost;
					cheapest = top;
				}
			}
			top = top->next;
		}
		if (cheapest)
			sort_frame(ss, cheapest);
	}
}

void	sort(t_stacks *s)
{
	stacks_get_median(s);
	while (stack_score(s->a) != s->total)
	{
		if ((s->a->size == 3)
				 || s->a->size == (s->total + (s->total % 2 != 0)) / 2)
		{
			sort_three(s);
			sort_stack(s, s->a);
			get_back_b(s);
		}
		else
			push_non_sorted(s);

		/* if (s->a->size == 3) */
		/* { */
		/* 	sort_three(s); */
		/* 	get_back_b(s); */
		/* } */
		/* else */
		/* 	push_non_sorted(s); */
	}
	order_stack(s);
}
