/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/21 13:55:15 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three(t_stacks *s)
{
	t_stack	*a;

	a = s->a;
	if (a->size < 3)
		return ;
	if (a->top == stack_get_max(a))
		sa(s);
	if (a->top->next->n > a->bot->n)
		rra(s);
	if (a->top->n > a->top->next->n)
		sa(s);
}

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
	if (f && !f->next)
		return (1);
	if (f->n < f->next->n)
		return (1);
	if (f->n > f->next->n && f == stack_get_max(s)
		&& f->next == stack_get_min(s))
		return (2);
	return (0);
}

/* void	push_to_b(t_stacks *s, t_frame *f) */
/* { */

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
	while (top && top->next)
	{
		if (!frame_sorted(s->a, top))
		{
			get_b_target(s, top);
			cost = cost_push(s, top);
			if (min_cost == 0 || cost < min_cost)
				min_cost = cost;
		}
	}
}

/* void	push_non_sorted(t_stacks *s) */
/* { */
/* 	t_frame	*cheapest; */
/* 	int		min_cost; */
/* 	int		cost; */
/* 	int		i; */

/* 	//get all targets in frames */
/* 	//get min_cost */
/* } */

/* void	stacks_sort(t_stacks *s) */
/* { */
/* 	if (stack_score(s->a) == s->a->size) */
/* 		return ; */
/* 	while (s->a->size > 3 && stack_score(s->a) < s->total) */
/* 	{ */

/* 	} */
/* } */

/*
** find 2 non sorted nbs. push the one that costs less to b.
*/
